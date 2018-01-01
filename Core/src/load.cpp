#include <iostream>
#include <string>
#include "load.h"

void test(int x)
{
	std::cout << x << std::endl;
}

DayAndTimeCombo Entry::inputTimeToCorrespondingDays(DayOfWeek& Days, Time& timeStart, Time& timeEnd)
{
	bool errorInStart = (timeStart < 0) ? 1 : (timeStart > 2400) ? 1 : 0;
	bool errorInEnd = (timeEnd > timeStart) ? 0 : 1;
	if (errorInStart)
	{
		std::cout << name << ": Invalid starting time" << std::endl;
	}
	if (errorInEnd)
	{
		std::cout << name << ": Invalid ending time" << std::endl;
	}
	return { Days,timeStart,timeEnd };
}

Entry::Entry()
{

}

Entry::~Entry()
{

}