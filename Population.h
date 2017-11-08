#include <vector>
#include "Person.h"

class Population {
private:
	std::vector<Person> people;
	int size;

public:
	// constructor: define a population of n people
	Population( int );

	// find some random person to infect a disease and let him sick for some "int-type input" days
	void random_infection( int );

	// return an int-type head count of total infected people at the time of inquiry
	int count_infected();
	
	// return an int-type head count of total people that have been sick during the run of disease
	int count_have_been_sick();

	// update everyone's status in the people vector
	void update();

	// show everybody's current status
	void show_status();

	// show the size of population
	void show_size();

	// set probability of disease transfer
	void set_probability_of_transfer( double );

	// count how many people are stable -- healed from disease or inoculated
	int count_stable();
	
	// randomly inoculate a fraction of population based on input
	void random_inoculation( double );
	
	// randomly transmit disease from a sick person to people he/she have contact with, limited by a transfer probability
	void random_disease_transmission( int, double );
};
