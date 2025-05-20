#ifndef ITER_HPP
#define ITER_HPP

template <typename t1>
void iter(t1 *ptr, int length, void (&func)(t1 &something))
{
    for (int i = 0; i < length; i++)
        func(ptr[i]);
}

#endif
