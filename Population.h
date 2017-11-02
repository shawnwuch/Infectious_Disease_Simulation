#include <vector>
#include "Person.h"

class Population {
private:
	std::vector<Person> people;
	int size;

public:
	// constructor: define a population of n people
	Population( int&& );

	// find some random person to infect a disease and let him sick for some "int-type input" days
	void random_infection( int );

	// return an int-type head count of total infected people at the time of inquiry
	int count_infected();

	// update everyone's status in the people vector
	void update();

	// show everybody's current status
	void show_status();

	// show the size of population
	void show_size();
};
