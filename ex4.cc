#include "Population.h"
#include <iostream>

int main() {
	
	std::cout << "This file is the first implementation of random disease transmission upon contact -- with specified number of contacted people." << std::endl;

	// Changeable variable, determines total # of runs and size of population
	int number_of_runs = 1000, population_size = 20;
	
	// For calculating avg steps disease spreads and avg number of stable people at the end of disease spread. Do not change.
	int number_of_steps = 0, number_of_stable_people = 0; 
	
	// You can manually run multiple tests with different transfer probability and group size	
	for ( int i = 0; i < number_of_runs ; ++i ) { 

		int step = 0;
    	
		// initialize a group of people
		Population somegroup( population_size );
	    somegroup.show_size();
			
		// first inoculate a fraction of the population, then infect a random susceptible person with the disease 
		somegroup.random_inoculation( 0 );
		somegroup.random_infection( 5 ); // disease requires 5 days to recover

		do {		
			++step;
			std::cout << "In step " << step << ", # of stable people: " << somegroup.count_stable() \
					  << ", # of sick people: " << somegroup.count_infected() << ": ";	
			somegroup.show_status();
			somegroup.update();
			
			// transmit the diease to a random contact if a probability criterion (2nd input) is met, up to 6 contact (1st input)
			somegroup.random_disease_transmission( 6, 0.2 );
		} while ( somegroup.count_infected() != 0 );
	
		// output final condition for each person in the group
		std::cout << "In step " << ++step << ", # of stable people: " << somegroup.count_stable() \
				  << ", # of sick people: " << somegroup.count_infected() << ": ";
		somegroup.show_status();

		// summary of how long the disease has been spreading
		std::cout << "Disease ran its course by step " << step << std::endl;

		number_of_steps += step;
		number_of_stable_people += somegroup.count_stable();
	}
	std::cout << "===== Summary =====" << std::endl;
	std::cout << "Disease will run at a average of " << number_of_steps * 1. / number_of_runs << " days" << std::endl;
	std::cout << "Average number of people in stable condition after the spread of disease is " << number_of_stable_people * 1. / number_of_runs << std::endl;
	return 0;
}
