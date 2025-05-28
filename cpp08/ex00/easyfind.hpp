#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

template <typename T>
typename T::iterator easyfind(T type, int nbr)
{
    return (std::find(type.begin(), type.end(), nbr));
}

#endif
