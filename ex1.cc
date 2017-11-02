#include "Person.h"
#include <iostream>

int main() {
	Person joe;
	int step=0;
	
	do {
		joe.update();	
		float bad_luck = (float) rand() / (float) RAND_MAX;
		if ( bad_luck > 0.95 )
			joe.infect(5);
		
		std::cout << "On day " << step << ", Joe is " << joe.status_string() << std::endl;
		++step;
	} while ( !joe.is_stable() );
	
	return 0;
}
