#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
private:
    int _size;
    T   *_array;
public:
    Array(void) : _size(0), _array(nullptr) {};
    Array(unsigned int n) : _size(n), _array(new T[n]) {};
    ~Array(void) { delete[] _array; };

    Array(const Array &src) : _size(src._size)
    {
        _array = new T[_size];
        for (int i = 0; i < _size; i++)
            _array[i] = src._array[i];
    };

    Array & operator = (const Array &src)
    {
        _size = src._size;
        delete[] _array;
        _array = new T[_size];
        for (int i = 0; i < _size; i++)
            _array[i] = src._array[i];
        return (*this);
    };



    //TODO:
    T &operator[](int index)
    {
        if (!_array || index > _size)
            throw std::out_of_range("Index out of range!");
        return (_array[index]);
    };

    int size(void) const { return _size; };
};

#endif
