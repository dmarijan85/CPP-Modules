#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <limits>
# include <cmath>
# include <iomanip>

class ScalarConverter
{
  private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &src);
        ScalarConverter &operator = (const ScalarConverter &src);
        ~ScalarConverter();
        void static convertToChar(double value, std::string &str);
        void static convertToInt(double value, std::string &str);
        void static convertToFloat(double value, std::string &str);
        void static convertToDouble(double value, std::string &str);

  public:
        void static convert(const std::string &str);

};

#endif
