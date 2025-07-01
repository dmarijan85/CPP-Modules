#include "BitcoinExchange.hpp"
#include <climits>
#include <string>

bool is_number(const std::string& s)
{
    bool anyNbr = false;
    std::string::const_iterator it = s.begin();
    while (it != s.end() && (std::isdigit(*it) || *it == '.'))
    {
        if (*it == '.' && !anyNbr)
            return false;
        if (std::isdigit(*it))
            anyNbr = true;
        ++it;
    }
    return (!s.empty() && it == s.end() && anyNbr);
}

void BitcoinExchange::readCSV(void)
{
    std::ifstream file("data.csv");

	if (!file.is_open())
		throw FileClosedException();
	std::string line;
	std::getline(file, line); //skip the first line
	while (std::getline(file, line))
	{
	    std::string value, date;
		std::istringstream ss(line);
		std::getline(ss, date, ',');
		std::getline(ss, value, '\n');

		if (!dateLegal(date))
		    throw InvalidDateFormatException();
		else if (!is_number(value) || std::stoll(value) < 0 || std::stoll(value) > INT_MAX)
		    throw InvalidPriceFormatException();
		else
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

void toInts(const std::string &date, int &year, int &month, int &day)
{
    std::string yearStr, monthStr, dayStr;
    std::istringstream ss(date);

    std::getline(ss, yearStr, '-');
    std::getline(ss, monthStr, '-');
	std::getline(ss, dayStr, '\n');

	year = std::stoi(yearStr, NULL);
	month = std::stoi(monthStr, NULL);
	day = std::stoi(dayStr, NULL);
}

bool BitcoinExchange::dateLegal(std::string date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;
	for (int i = 0; i < 10; i++)
		if (!isdigit(date[i]) && (i != 4 && i != 7))
			return false;

    int year, month, day;
    toInts(date, year, month, day);

	if (year < 0 || day <= 0 || day > 31 || month <= 0 || month > 12)
	    return false;

	switch (month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (day <= 0 || day > 31)
				return false;
			break;
		case 4: case 6: case 9: case 11:
			if (day <= 0 || day > 30)
				return false;
			break;
		case 2:
		    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
			{
				if (day <= 0 || day > 29)
					return false;
			} else if (day <= 0 || day > 28)
				return false;
			break;
		default:
		    return false;
	}

	return true;
}

double BitcoinExchange::closestDate(std::string date)
{
    std::map<std::string, double>::iterator it = _prices.find(date);
	if (it != _prices.end()) {
	    return (it->second);
	} else {
		std::map<std::string, double>::iterator it2 = _prices.lower_bound(date);
		if (it2 == _prices.begin() && date < it2->first) {
                std::cout << "Error: Bitcoin did not exist on database!" << std::endl;
                return -1;
		} else {
		    --it2;
			return (it2->second);
		}
	}

    return (_prices[date]);
}

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
	    std::string date, nbr;
		std::istringstream ss(line);

		std::getline(ss, date, '|');
		if (date[10] == ' ')
		    date = date.substr(0, date.size() - 1);
		std::getline(ss, nbr, '\n');
		if (nbr.size() > 1)
		    nbr = nbr.substr(1, nbr.size());

		if (!dateLegal(date))
		    std::cout << "Date format is wrong!" << std::endl;
		else if (!is_number(nbr))
		    std::cout << "Quantity must be a number!" << std::endl;
		else if (std::stoll(nbr) < 0)
		    std::cout << "Quantity cannot be negative!" << std::endl;
		else if (std::stoll(nbr) > INT_MAX)
		    std::cout << "Quantity has to fit inside INT_MAX!" << std::endl;
		else
		    std::cout << date << " => " << nbr << " = " << std::stod(nbr) * closestDate(date) << std::endl;
	}
	file.close();
}
