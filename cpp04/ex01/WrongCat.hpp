#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
	public:
		WrongCat(void);
		WrongCat(const WrongCat& copy);
		~WrongCat(void);
		WrongCat&	operator=(const WrongCat& copy);
		void	makeSound(void) const;
};

#endif
