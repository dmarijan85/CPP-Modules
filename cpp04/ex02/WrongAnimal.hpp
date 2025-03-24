#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string	type;

	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &copy);

		virtual ~WrongAnimal(void);

		WrongAnimal &operator=(const WrongAnimal &copy);

		std::string		getType(void) const;
		void			setType(const std::string type);

		virtual void	makeSound(void) const;
};
#endif
