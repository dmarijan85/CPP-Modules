#ifndef ARRAY_HPP
#define ARRAY_HPP

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

    Array & operator = (const Array &src)
    {
        _size = src._size;
        delete[] _array;
        _array = new T[_size];
        for (int i = 0; i < _size; i++)
            _array(i) = src._array(i);
        return (*this);
    };

    Array(const Array &src) : _size(src._size)
    {
        this = src;
    };

    //TODO:
    T &operator[](int index);

    int size(void) const { return _size; };
};

#endif
