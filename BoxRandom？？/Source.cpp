#include <iostream>
#include "BoxRandom.h"

int main() {
	BoxRandom<std::mt19937> BR;

	for (std::size_t i = 0; i < BR.Size(); i++) {
		std::cout << BR.Get() << ',';
	}
	std::cout << std::endl;
	for (std::size_t i = 0; i < BR.Size(); i++) {
		std::cout << BR.Get() << ',';
	}
	std::cout << std::endl;
	return 0;
}