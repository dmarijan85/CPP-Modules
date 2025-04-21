#ifndef HARLFILTER_HPP
# define HARLFILTER_HPP

# include <iostream>
# include <string>

#define RESET   "\033[0m"
#define BOLD     "\033[1m"
#define RED_BACKGROUND "\033[41m"
#define RED     "\033[31m"
#define BOLD_RED "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class Harl
{
    public:
        Harl( void );
        ~Harl( void );
		int	exec( std::string message );

    private:
        void        debug( void );
        void        info( void );
        void        warning( void );
        void        error( void );
        std::string levels[4];
        void        (Harl::*f[4])( void );
};

#endif
