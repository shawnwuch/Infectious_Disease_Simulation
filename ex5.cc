#include "Population.h"
#include <iostream>
#include <fstream>

int main() {
		
	// Changeable variable, determines total # of runs and size of population
	int number_of_runs = 200, population_size = 200;
	
	std::cout << "This file investigates the length of disease run with respect to disease transfer probability and inoculation fraction of a group of people." \
			  << "This file also computes the average number of people infected by the disease for each (transfer_probability + inoculation_fraction) set." \
			  << std::endl;
	std::ofstream myfile;
	myfile.open ("data.txt", std::ios::app);
	myfile << "transfer_probability    inoculation_fraction    avg_steps    avg_stable_ppl    avg_num_of_people_have_been_sick\n";
	
	// Perform a parametric study on disease transmission for the given population size.
	for ( int inoculation_fraction = 0; inoculation_fraction <= 95; inoculation_fraction += 5 ) {	
		for ( int transfer_probability = 0; transfer_probability <= 100; transfer_probability += 5 ) {
			
			// For calculating avg steps disease spreads and avg number of stable people at the end of disease spread. Do not change.
			int number_of_steps = 0, number_of_stable_people = 0, number_of_people_have_been_sick = 0; 
			
			// run multiple tests with different transfer probability
			for ( int i = 0; i < number_of_runs ; ++i ) { 

				int step = 0;
				
				// initialize a group of people
				Population somegroup( population_size );
				//somegroup.show_size();
					
				// first inoculate a fraction of the population, then infect a random susceptible person with the disease 
				somegroup.random_inoculation( inoculation_fraction * 0.01 );
				somegroup.random_infection( 5 ); // disease requires 5 days to recover

				do {		
					++step;
					somegroup.update();
					
					// transmit the diease to a random contact if a probability criterion (2nd input) is met, up to 6 contact (1st input)
					somegroup.random_disease_transmission( 6, transfer_probability * 0.01 );
				} while ( somegroup.count_infected() != 0 );
			
				// summary of how long the disease has been spreading
				number_of_steps += step;
				number_of_stable_people += somegroup.count_stable();
				number_of_people_have_been_sick += somegroup.count_have_been_sick();	
			}
		
			// store the averaged output to myfile	
			myfile << transfer_probability * 0.01 << " " << inoculation_fraction * 0.01 << " " << number_of_steps * 1. / number_of_runs \
				   << " " << number_of_stable_people * 1. / number_of_runs << " " \
				   << number_of_people_have_been_sick * 1. / number_of_runs << "\n";
		}
	}
	myfile.close();
	return 0;
}
