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

//-------------------------------------------------------------------------------------------------------------//
// Taken from Loki Astari (https://stackoverflow.com/questions/1120140/how-can-i-read-and-parse-csv-files-in-c) 
std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str)
{
	std::vector<std::string>   result;
	std::string                line;
	std::getline(str, line);

	std::stringstream          lineStream(line);
	std::string                cell;

	while (std::getline(lineStream, cell, ','))
	{
		result.push_back(cell);
	}
	// This checks for a trailing comma with no data after it.
	if (!lineStream && cell.empty())
	{
		// If there was a trailing comma then add an empty element.
		result.push_back("");
	}
	return result;
}

std::string const& CSVRow::operator[](std::size_t index) const
{
	return m_data[index];
}

std::size_t CSVRow::size() const
{
	return m_data.size();
}

void CSVRow::readNextRow(std::istream& str)
{
	std::string         line;
	std::getline(str, line);

	std::stringstream   lineStream(line);
	std::string         cell;

	m_data.clear();
	while (std::getline(lineStream, cell, ','))
	{
		m_data.push_back(cell);
	}
	// This checks for a trailing comma with no data after it.
	if (!lineStream && cell.empty())
	{
		// If there was a trailing comma then add an empty element.
		m_data.push_back("");
	}
}

std::istream& operator>>(std::istream& str, CSVRow& data)
{
	data.readNextRow(str);
	return str;
}

CSVIterator::CSVIterator(std::istream& str) :m_str(str.good() ? &str : NULL) { ++(*this); }
CSVIterator::CSVIterator() :m_str(NULL) {}

// Pre Increment
CSVIterator& CSVIterator::operator++() { if (m_str) { if (!((*m_str) >> m_row)) { m_str = NULL; } }return *this; }
// Post increment
CSVIterator CSVIterator::operator++(int) { CSVIterator    tmp(*this); ++(*this); return tmp; }
CSVRow const& CSVIterator::operator*()   const { return m_row; }
CSVRow const* CSVIterator::operator->()  const { return &m_row; }

bool CSVIterator::operator==(CSVIterator const& rhs) { return ((this == &rhs) || ((this->m_str == NULL) && (rhs.m_str == NULL))); }
bool CSVIterator::operator!=(CSVIterator const& rhs) { return !((*this) == rhs); }
//-------------------------------------------------------------------------------------------------------------//