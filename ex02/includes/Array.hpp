
#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <string>

template<typename T>

class Array {

    private:
        T*              _array;
        unsigned int    _size;
    
    public:
        Array(void);
        Array(unsigned int n);
        Array(const Array<T>& copy);

        Array<T>& operator=(const Array<T>& copy);
        T& operator[](unsigned int n);

        class IndexOutOfBound : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        unsigned int size(void);

        ~Array(void);
};

template<typename T>

const char* Array<T>::IndexOutOfBound::what() const throw() {
    return "Index inexistent\n";
}

template<typename T>

Array<T>::Array() : _array(NULL), _size(0) {};

template<typename T>

Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {};

template<typename T>

Array<T>::Array(const Array<T>& copy) : _array(new T[copy._size]), _size(copy._size) {
    for (int i = 0; i < _size; i++)
            _array[i] = copy._array[i];
};

template<typename T>

Array<T>& Array<T>::operator=(const Array<T>& copy) {
    if (this != *copy) {
        if (_array)
            delete[] _array;
        if (copy._array) {
            _size = copy._size;
            _array = new T[copy._size];
            for (int i = 0; i < size(); i++)
                _array[i] = copy._array[i];
        }
        else {
            _size = 0;
            _array = NULL;
        }
    }

    return *this;
}

template<typename T>

T& Array<T>::operator[](unsigned int n) {
    if (n >= _size)
        throw IndexOutOfBound();
    
    return _array[n];
}

template<typename T>

unsigned int Array<T>::size(void) {
    return _size;
}

template<typename T>

Array<T>::~Array(void) {
    if (_array)
        delete[] _array;
}

#endif