infinite_monkey: infinite_monkey.o 
	clang++ -o infm infinite_monkey.o 

infinite_monkey.o: infinite_monkey.cpp
	clang++ -c infinite_monkey.cpp 

clean: 
	rm *.o infm