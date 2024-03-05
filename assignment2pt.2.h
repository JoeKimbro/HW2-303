#pragma once
#include <vector>
#include <iostream>
using namespace std;
class Vector {
private:
	vector<int> stack;

public:

	bool empty() const {
		return stack.empty();

	}

	void push(int value) {
		stack.push_back(value);

	}

	void pop() {
		if (!empty()) {
			stack.pop_back();
		}
	}

	int top() const {
		if (!empty()) {
			return stack.back();

		}
	}

	void display() const { // this will display the elements in the stack
		if (empty()) {
			std::cout << "Stack is empty.\n";
		}
		else {
			std::cout << "Stack elements: ";
			for (int value : stack) {
				std::cout << value << " ";
			}
			std::cout << "\n";
		}
	}

	double getAverage() const {
		if (!empty()) {
			int sum = 0;
			for (int value : stack) {
				sum += value;
			}

			return static_cast<double>(sum) / stack.size();
		}
		else {
			std::cerr << "Stack is empty. Cannot calculate average.\n";
			return 0.0;
		}
	}
};