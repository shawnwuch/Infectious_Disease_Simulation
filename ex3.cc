#include "Population.h"
#include <iostream>

int main() {
	
	std::cout << "This file implements the disease transmission function to directly adjacent neighbors in a 1-D space." << std::endl;

	// Changeable variable, determines total # of runs and size of population
	int number_of_runs = 10, population_size = 200;
	
	// For calculating avg steps disease spreads and avg number of stable people at the end of disease spread. Do not change.
	int number_of_steps = 0, number_of_stable_people = 0; 
	
	// run multiple tests with different transfer probability and group size	
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

			// set the probability for disease transfer, infect immediate neighbors if probability criteria is met
			somegroup.set_probability_of_transfer(0.5);
		} while ( somegroup.count_infected() != 0 );
	
		// to obtain similar output as shown on the book, not absolutely required
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
