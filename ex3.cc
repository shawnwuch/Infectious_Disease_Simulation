#include "Population.h"
#include <iostream>

int main() {
	
	int number_of_runs = 5, population_size = 20, number_of_steps = 0, number_of_stable_people = 0; 
	// run multiple tests with different transfer probability and group size	
	for ( int i = 0; i < number_of_runs ; ++i ) { 

    	// initialize a group of people
		Population somegroup( population_size );
	    somegroup.show_size();
		
		int step = 0;
		somegroup.random_infection( 5 );

		do {		
			++step;
			std::cout << "In step " << step << ", # of stable people: " << somegroup.count_stable() \
					  << ", # of sick people: " << somegroup.count_infected() << ": ";	
			somegroup.show_status();
			somegroup.update();
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
	std::cout << "Disease will run at a average of " << number_of_steps / number_of_runs << " days" << std::endl;
	std::cout << "Average number of people in stable condition after the spread of disease is " << number_of_stable_people / number_of_runs << std::endl;
	return 0;
}
