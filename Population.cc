#include "Population.h"
#include <vector>

Population::Population( int &&n ) { people = std::vector<Person>(n); };

// infect a random person inside a population
void Population::random_infection() {
	float random_fraction = (float) rand() / (float) RAND_MAX;
	random_fraction * people.size()
};
