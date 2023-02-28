#include <iostream>
#include <list>

int main(int argc, char** argv) {

	size_t size{};

	std::cout << "[IN]: " << std::endl;
	std::cin >> size;

	std::list<int> l(size);

	for (auto& el : l) { std::cin >> el; }

	l.sort([](int a, int b) { return a > b; });
	l.unique();

	std::cout << "[OUT]: " << std::endl;
	for (const auto& el : l) { std::cout << el << std::endl; }

	return 0;
}