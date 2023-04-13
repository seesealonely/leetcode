ex:636.ExclusiveTimeofFunctions
lib.a:head.o
	ar -crv $@ $<
head.o:head.cc
636.ExclusiveTimeofFunctions:636.ExclusiveTimeofFunctions.cc lib.a
	g++ -Wall -g $^ -o $@
clean:
	rm -f  636.ExclusiveTimeofFunctions
