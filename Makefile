infinite_monkey: driver/infinite_monkey.o driver/errors.o lexer/token.o driver/scanner.o
	clang++ -o infm driver/infinite_monkey.o driver/errors.o lexer/token.o driver/scanner.o

infinite_monkey.o: driver/infinite_monkey.cpp
	clang++ -c driver/infinite_monkey.cpp 

scanner.o: driver/scanner.cpp
	clang++ -c driver/scanner.cpp

errors.o: driver/errors.cpp
	clang++ -c driver/errors.cpp 

token.o: lexer/token.cpp
	clang++ -c lexer/token.cpp 

clean: 
	rm driver/*.o
	rm lexer/*.o
	rm infm