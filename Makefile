CC		= g++ #clang++ #g++ #icpc
CFLAGS	= --std=c++11 -Wall -Wextra #-pg for profiling and debugging
LDFLAGS	=
LIBS	=

# Rules
info:
	@echo "You can do: make exN, where N is the number of exercise you wish to compile."

%.o: %.cc
	$(CC) $(CFLAGS) -c $<


#% : %.cc
#PROGRAMS = ex1 ex5
#.SECONDEXPANSION:
#${PROGRAMS} : Person.o Population.o $$@.o
#	$(CC) $(CFLAGS) -o main $^

.PRECIOUS: %.o
ex%: Person.o Population.o ex%.o
	$(CC) $(CFLAGS) -o main $^

clean:
	rm -f main *~ *.o main

