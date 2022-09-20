#include <iostream>
#include <string>

int sum(int a, int b) {
	return a + b;
}

int main() {

	int a = 0;
	int b = 0;

	std::string input;
	std::cout << "Enter value for A:" << std::endl;
	getline(std::cin, input);

	std::cout << "Enter value for B:" << std::endl;
	getline(std::cin, input);


	std::cout << "Sum of A and B is:" << sum (a, b) << std::endl;

	int run = 1;
	while (run) {
		std::string input;
		std::cout << "Press 0 to exit, any other to continue" << std::endl;
		getline(std::cin, input);
		run = std::stoi(input);
	}

	return 0;
}