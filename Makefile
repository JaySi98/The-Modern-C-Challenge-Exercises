all : argument.o primes.o ex1 ex2 ex3 ex4 ex5 ex10 ex11 clean

argument.o : Libs/argument.h
	g++ -c Libs/argument.cpp 

primes.o : Libs/primes.h
	g++ -c Libs/primes.cpp 

ex1 : section1/ex1.cpp
	gcc -o Execs/ex1 section1/ex1.cpp argument.o 

ex2 : section1/ex2.cpp
	gcc -o Execs/ex2 section1/ex2.cpp argument.o 

ex3 : section1/ex3.cpp
	gcc -o Execs/ex3 section1/ex3.cpp argument.o 

ex4 : section1/ex4.cpp
	g++ -o Execs/ex4 section1/ex4.cpp argument.o primes.o 

ex5 : section1/ex5.cpp
	g++ -o Execs/ex5 section1/ex5.cpp argument.o primes.o 

ex10 : section1/ex10.cpp
	g++ -o Execs/ex10 section1/ex10.cpp 

ex11 : section1/ex11.cpp
	g++ -o Execs/ex11 section1/ex11.cpp argument.o

clean :
	rm primes.o argument.o