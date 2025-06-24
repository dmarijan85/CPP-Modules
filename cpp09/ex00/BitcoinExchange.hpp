#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


class BitcoinExchange
{
public:
    BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange(void);

	void exchange(const std::string &filename);

	//exceptions
	class FileClosedException : public std::exception {
	public:
	    const char *what() const throw() {
					return "Error upon opening file!";
					}
	};

	class WrongFormatException : public std::exception {
	public:
	    virtual const char *what() const throw() {
					return "File has wrong format!";
					}
	};

	class InvalidPriceFormatException : public std::exception {
	public:
	    virtual const char *what() const throw() {
					return "Price format is wrong!";
					}
	};

private:
    std::map<std::string, double> _prices;

    void readCSV(void);

};

#endif
