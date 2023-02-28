#include <iostream>
#include <new>
#include "vector/vector.hpp"

int main(int argc, char** argv) {

	container::vector<int> v;

	v.push_back(10);
	v.push_back(8);

	std::cout << v.at(0) << std::endl;
	std::cout << v.at(1) << std::endl;

	try {
		container::vector<int> v(-4);
	}
	catch (std::bad_array_new_length& ex) {
		std::cout << ex.what() << ": negative or zero size" << std::endl;
	}

	return 0;
}