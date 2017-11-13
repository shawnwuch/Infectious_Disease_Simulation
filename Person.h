#include <string>
#include <vector>

class Person {
private:
	int status = 0 ; // 0 = healthy and susceptible, -1 = inoculated or recovered, positive n = n days to go before recovery. 
	bool have_been_sick = false; // false = healthy (susceptible or recovered / inoculated), true = have been sick

public:
	Person(); // default constructor, creates a healthy and susceptible person
	std::string status_string(); // report current health status in a string
	void update();	
	void infect( int ); // infect a person, change his/her status to n days to go before recovery
	void inoculate(); // inoculate a person, set status to -1
	bool is_stable(); // report whether the person has been sick and is recovered, true for stable, false for unstable
	bool been_sick(); // return a boolean showing if a person has ever been sick due to a disease

	// accessor, return an int-type current status
	int current_status(); 	
};

