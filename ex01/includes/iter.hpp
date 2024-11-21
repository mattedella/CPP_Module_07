
#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void	printItems(const T& element) {
	std::cout << element << std::endl;
}

template<typename A, typename L, typename F>

void iter(A* array, L lenght, F function) {
    for (L i = 0; i < lenght; i++) {
        function(array[i]);
    }
}


#endif