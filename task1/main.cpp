#include <iostream>
#include <string>
#include <list>
#include <algorithm>

int main(int argc, char** argv) {

	std::string word{};

	std::cout << "[IN]: ";
	std::getline(std::cin, word);

	std::list<std::pair<char, int>> l{};

	for (auto& el : word) {

		std::string count_el{};

		std::copy_if(word.begin(), word.end(), back_inserter(count_el), [&el](const char& ch) { return ch == el; });

		l.push_back({ el, size(count_el) });
	}

	l.sort([](std::pair<char, int>& a, std::pair<char, int>& b) { return a.second > b.second; });
	l.unique();

	std::cout << "[OUT]:" << std::endl;
	for (auto& el : l) { std::cout << el.first << ": " << el.second << std::endl; }

	return 0;
}