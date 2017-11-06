#include <iostream>
#include "Population.h"
#include <vector>
#include <cmath>

// constructor
Population::Population( int n ) { people = std::vector<Person>(n); size = n; };

// infect a random person inside a population
void Population::random_infection( int n ) {
	//float random_fraction = (float) rand() / (float) RAND_MAX;
	//int element = ceil( random_fraction * people.size() ); // randomly choose a element from a vector, index = element - 1
	
	int element = rand() % size;
	// infect the person if the person is healthy and susceptible, otherwise do a recursive call
	if ( people[ element ].current_status() == 0 ) {
		people[ element ].infect( n ); // infect the person for n days 	
	} else {
		Population::random_infection( n );
	}
};


// count how many people are infected and return an integer
int Population::count_infected() {
	int infected_count = 0;
	
	for ( auto &i : people ) {
		if ( i.current_status() > 0 ) {
			++infected_count;			
		}
	}
	return infected_count;
};


// update everyone's health status by 1 step
void Population::update() {
	for ( auto &i : people ) {
		i.update();
	}
};


// show everybody's current status
void Population::show_status() { 
	for ( auto &i : people ) {
		if ( i.current_status() > 0 ) { std::cout << "+ "; } // infected
		else if ( i.current_status() == -1 ) { std::cout << "- "; } // recovered or inoculated
		else { std::cout << "o "; } // susceptible
	}
	std::cout << std::endl;
};

void Population::show_size() {
	std::cout << "Size of population: " << size << std::endl;
};

// parse through every person, depending on sick status determining the spread of disease by user-defined probability
void Population::set_probability_of_transfer( double probability ) {
	// create a random fraction, spread the disease to neighbors if the fraction is smaller than specified probability, otherwise do nothing
	for ( auto i = people.begin(); i < people.end(); ++i ) {
		// if the person is sick and probability criteria for spreading the disease is met, if current_status()==5 means that the person just got sick in 
		// current step so he(she) is not contagious
		if ( i->current_status() > 0 && i->current_status() < 5 ) {	
			float random_fraction = (float) rand() / (float) RAND_MAX;
			
			if (random_fraction <= probability ) {
				// spread the disease to healthy and not inoculated neighbors
				if ( i == people.begin() && (i+1)->current_status() == 0 ) { (i+1)->infect( 5 ); }
				else if ( i == people.end() && (i-1)->current_status() == 0 ) { (i-1)->infect( 5 ); }
				else { 
					if ( (i-1)->current_status() == 0 ) { (i-1)->infect( 5 ); }
					if ( (i+1)->current_status() == 0 ) { (i+1)->infect( 5 ); } 
				}
			}
		}
	}
};


// count how many people in the group are stable -- healed from disease or inoculated
int Population::count_stable() {
	int stable_count = 0;
	for ( auto &i : people ) {
		if ( i.is_stable() ) { stable_count += 1; }
	}
	return stable_count;
};

// inoculate a random fraction of people based on input
void Population::random_inoculation( double fraction ) {
	// calculate number of inoculated people according to input fraction
	int num_inoculated = round( fraction * size ), count = 0;
	std::cout << "inoculation target: " << num_inoculated << std::endl;
	while ( count < num_inoculated ) {
		int index = rand() % size; // create a random index in the range of 0 to size-1 
		
		// inoculate the person if healthy and susceptible
		if ( people[ index ].current_status() == 0 ) {
			people[ index ].current_status() = -1;
			++count;
		}
	}
};
