#include "Person.h"
#include <string>
#include <iostream>
#include <stdexcept>


// Person class constructors and methods
Person::Person() {};

std::string Person::status_string() {
	// return a string according to a person's status
	// -1 = recovered, 0 = susceptible, positive n = n days to go before recovery
	if ( status == -1 ) return "recovered";
	else if (status == 0 ) return "susceptible";
	else if ( status > 0 ) return "sick (" + std::to_string(status) + " to go)";
	else { throw std::invalid_argument( "The person's health status is undefined" ); }
};

void Person::update() {
	// update a person's status to next day, susceptible and inoculated status will be carried over to next day
	if ( status > 0 ) { 
		status = status - 1;  // if sick, -1 day for recovery 
		if ( status == 0 ) status = -1 ; 
	} // if fully recovered, the person becomes inoculated
};

// passing the integer n as a rvalue reference to infect()
void Person::infect( int &&n ) {
	// infect a person and let disease to run for n days
	if ( status >= 0 ) status = status + n; 	
};

bool Person::is_stable() {
	// report the stability of a person, -1 = true, others = false
	if ( status == -1 ) { return true; }
	else if (status >= 0 ) { return false; }
	else { throw std::invalid_argument( "The person's health status is undefined" ); }
};

