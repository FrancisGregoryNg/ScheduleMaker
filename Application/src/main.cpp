#include <iostream>
#include <string>
#include "load.h"
#include "analyze.h"
#include "display.h"

int main()
{
	test(5);
	Entry x;
	x.test = "hello";
	std::cout << x.test << std::endl;
	int y = Entry::_0545pm;
	std::cout << y << std::endl;
	std::cin.get();
	/*
	std::ifstream       file("plop.csv");

	CSVRow              row;
	while (file >> row)
	{
		std::cout << "4th Element(" << row[3] << ")\n";
	}

	std::ifstream       file("plop.csv");

	for (CSVIterator loop(file); loop != CSVIterator(); ++loop)
	{
		std::cout << "4th Element(" << (*loop)[3] << ")\n";
	}
	*/
}	