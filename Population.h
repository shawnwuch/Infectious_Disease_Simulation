#include <vector>
#include "Person.h"

class Population {
private:
	std::vector<Person> people;

public:
	// constructor: define a population of n people
	Population( int&& );
	void random_infection();
};
