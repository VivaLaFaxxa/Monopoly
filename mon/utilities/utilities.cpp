#include <random> 
#include <iostream>

int rollDice() {
	//Generates two random numbers between 1 and 6.
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distr(1, 6);          
	int n1 = distr(gen);
	int n2 = distr(gen);
	std::cout << n1 << "\n" << n2 << std::endl;
	//Returns the sum of the two numbers 
	return n1 + n2;
}