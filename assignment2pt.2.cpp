// assignment2pt.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "assignment2pt.2.h"
#include <vector>

int choice;
int main() {
    Vector stack;
    int num;
    std::cout << "Enter a set of numbers (enter -1 to finish):\n";
    while (true) {
        std::cin >> num;
        if (num == -1) {
            break;
        }
        stack.push(num);
    }

    do {
        // Display menu
        std::cout << "\nMenu:\n";
        std::cout << "1. Push\n";
        std::cout << "2. Pop\n";
        std::cout << "3. The Average of the Stack Elements\n";
        std::cout << "4. If the Stack is Empty or Not?\n";
        std::cout << "5. Top if the Stack\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {


        case 1: {
            int value;
            std::cout << "Enter value to push:  ";
            std::cin >> value;
            stack.push(value);
            break;
        }

        case 2: {
            if (!stack.empty()) {
                stack.pop();
                break;
            }
            else {
                std::cout << "STACK IS EMPTY\n";
            }

        }
        case 3: {
            if (!stack.empty()) {
                double average = stack.getAverage();
                std::cout << "Average of the Stack Elements: " << average << "\n";
            }
            else {
                std::cout << "STACK IS EMPTY\n";
            }
            break;
        }

        case 4: {
            if (!stack.empty()) {
                std::cout << "STACK IS NOT EMPTY\n ";

            }
            else {
                std::cout << "STACK IS EMPTY\n";
            }

            break;
        }

        case 5: {
            if (!stack.empty()) {
                std::cout << "Top: " << stack.top() << "\n";

            }
            else {
                std::cout << "List is empty.\n";
            }

            break;
        }

        case 0: {
            std::cout << "Exiting program.\n";
            break;
        }
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
        stack.display();

    } while (choice != 0);

    return 0;
}
