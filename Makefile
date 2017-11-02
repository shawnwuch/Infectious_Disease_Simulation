CC		= icpc
CFLAGS	= --std=c++11 -Wall -Wextra #-pg for profiling and debugging
LDFLAGS	=
LIBS	=

# Rules
info:
	@echo "You can do: make exN, where N is the number of exercise you wish to compile."

%.o: %.cc
	$(CC) $(CFLAGS) -c $<

ex1: Person.o ex1.o
	$(CC) $(CFLAGS) -o main $^

clean:
	rm -f main *~ *.o main
