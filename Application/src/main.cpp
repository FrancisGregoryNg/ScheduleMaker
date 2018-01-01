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
}	