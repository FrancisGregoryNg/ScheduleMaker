#pragma once

void test(int x);

struct DayAndTimeCombo
{
	int day;
	int timeStart;
	int timeEnd;
};

class Entry
{
public:
	enum DayOfWeek : char
	{
		Sunday = 1, Monday = 2, Tuesday = 3, Wednesday = 4, Thursday = 5, Friday = 6, Saturday = 7
	};
	enum Time : int
	{
		_1200am =    0, _1215am =   15, _1230am =   30, _1245am =   45,
		_0100am =  100, _0115am =  115, _0130am =  130, _0145am =  145,
		_0200am =  200, _0215am =  215, _0230am =  230, _0245am =  245,
		_0300am =  300, _0315am =  315, _0330am =  330, _0345am =  345,
		_0400am =  400, _0415am =  415, _0430am =  430, _0445am =  445,
		_0500am =  500, _0515am =  515, _0530am =  530, _0545am =  545,
		_0600am =  600, _0615am =  615, _0630am =  630, _0645am =  645,
		_0700am =  700, _0715am =  715, _0730am =  730, _0745am =  745,
		_0800am =  800, _0815am =  815, _0830am =  830, _0845am =  845,
		_0900am =  900, _0915am =  915, _0930am =  930, _0945am =  945,
		_1000am = 1000, _1015am = 1015, _1030am = 1030, _1045am = 1045,
		_1100am = 1100, _1115am = 1115, _1130am = 1130, _1145am = 1145,
		_1200pm = 1200, _1215pm = 1215, _1230pm = 1230, _1245pm = 1245,
		_0100pm = 1300, _0115pm = 1315, _0130pm = 1330, _0145pm = 1345,
		_0200pm = 1400, _0215pm = 1415, _0230pm = 1430, _0245pm = 1445,
		_0300pm = 1500, _0315pm = 1515, _0330pm = 1530, _0345pm = 1545,
		_0400pm = 1600, _0415pm = 1615, _0430pm = 1630, _0445pm = 1645,
		_0500pm = 1700, _0515pm = 1715, _0530pm = 1730, _0545pm = 1745,
		_0600pm = 1800, _0615pm = 1815, _0630pm = 1830, _0645pm = 1845,
		_0700pm = 1900, _0715pm = 1915, _0730pm = 1930, _0745pm = 1945,
		_0800pm = 2000, _0815pm = 2015, _0830pm = 2030, _0845pm = 2045,
		_0900pm = 2100, _0915pm = 2115, _0930pm = 2130, _0945pm = 2145,
		_1000pm = 2200, _1015pm = 2215, _1030pm = 2230, _1045pm = 2245,
		_1100pm = 2300, _1115pm = 2315, _1130pm = 2330, _1145pm = 2345,
	};

	std::string test;

private:
	std::string name;
	std::string section;
	std::string room;
	std::string professor;

public:
	DayAndTimeCombo inputTimeToCorrespondingDays(DayOfWeek& Days, Time& timeStart, Time& timeEnd);
	Entry();
	~Entry();
};