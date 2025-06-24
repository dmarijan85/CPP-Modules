#include "BitcoinExchange.hpp"

void BitcoinExchange::readCSV(void)
{
    std::ifstream file("data.csv");

	if (!file.is_open())
		throw FileClosedException();
	std::string line;
	std::getline(file, line); //skip the first line
	while (std::getline(file, line))
	{
	    std::string value;
		std::string date;
		std::istringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, value, '\n');

		std::cout << date << ", " << value << std::endl;
	    _prices[date] = stod(value);
	}

}

BitcoinExchange::BitcoinExchange() {
	readCSV();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
	if (this != &cpy)
		*this = cpy;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &cpy)
{
	if (this != &cpy)
		this->_prices = cpy._prices;
	return *this;
}

BitcoinExchange::~BitcoinExchange(void){}

void BitcoinExchange::exchange(const std::string &filename)
{
    std::ifstream file(filename);

	if (!file.is_open())
		throw FileClosedException();

	std::string line;
	//first line has to be "date | value"
	std::getline(file, line);
	if (line != "date | value")
		throw WrongFormatException();

	while (std::getline(file, line))
	{


	}
	file.close();
}
