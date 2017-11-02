#include <iostream>
#include "Population.h"
#include <vector>
#include <cmath>

Population::Population( int &&n ) { people = std::vector<Person>(n); size = n; };

// infect a random person inside a population
void Population::random_infection( int n ) {
	float random_fraction = (float) rand() / (float) RAND_MAX;
	int element = ceil( random_fraction * people.size() ); // randomly choose a element from a vector, index = element - 1
	//std::cout << "random_fraction: " << random_fraction << ", element: " << element << " " << rand() << " " << RAND_MAX << std::endl; // for debugging
	people[ element - 1 ].infect( n ); // infect the person for n days 	
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
		if ( i.current_status() > 0 ) { std::cout << "+ "; }
		else { std::cout << "- "; }
	}
	std::cout << std::endl;
};

void Population::show_size() {
	std::cout << "Size of population: " << size << std::endl;
};
