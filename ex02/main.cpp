
#include "includes/Array.hpp"

int main(void) {
    
    	Array<int> empty;

	unsigned int	i = 5;
	int	gino[6] = {0, 1, 2, 3, 4, 5};
 
	Array<double>	full(i);
	

	for (unsigned int j = 0; j < i; j++) {
		full[j] = gino[j];
		if (full[j] == gino[j]) {
			std::cout << "Full is " << full[j] << " as gino is " << gino[j] << std::endl;
		}
	}

	try {
		std::cout << full[full.size() + 1] << "exist!!!\n";
	}
    catch (std::exception & ex) {
		std::cout << "Exception error: " << ex.what() << std::endl;
	}

	return 0;
}