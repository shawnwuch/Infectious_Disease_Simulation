// to be edited
#include "Population.h"
#include <iostream>

int main() {
	
	// initialize with a group of 10 people
	Population somegroup( 10 );
	somegroup.show_size();

	int step=0;
	somegroup.random_infection( 5 );

	do {		
		++step;
		somegroup.set_probability_of_transfer(0.5);
		std::cout << "In step " << step << ", # of sick people: " << somegroup.count_infected() << ": ";	
		somegroup.show_status();
		somegroup.update();
	} while ( somegroup.count_infected() != 0 );
	
	// to obtain similar output as shown on the book, not absolutely required
	std::cout << "In step " << ++step << ", # of sick people: " << somegroup.count_infected() << ": ";
	somegroup.show_status();

	// summary of how long the disease has been spreading
	std::cout << "Disease ran its course by step " << step << std::endl;

	return 0;
}
