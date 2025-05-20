#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename type>
void swap(type &first, type &second)
{
    type temp;

    temp = second;
    second = first;
    first = temp;
}

template <typename type>
type min(type one, type two)
{
    if (two > one)
        return one;
    else if (one > two)
        return two;
    else
        return two;
}

template <typename type>
type max(type one, type two)
{
    if (one > two)
        return one;
    else if (two >= one)
        return two;
    else
        return two;
}

#endif
