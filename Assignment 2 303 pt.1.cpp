#include "Assignment 2 303 pt.1.h"
#include <iostream>
#include <vector>


int choice;
int main() {
    linked_list<int> list;
    int num;
    std::cout << "Enter a set of numbers (enter -1 to finish):\n";
    while (true) {
        std::cin >> num; 
        if (num == -1) { // once "-1" is entered it will continue
            break;
        }
        list.push_back(num);
    }

    
    do {
        // Display menu
        std::cout << "\nMenu:\n";
        std::cout << "1. Push Front\n";
        std::cout << "2. Push Back\n";
        std::cout << "3. Pop Front\n";
        std::cout << "4. Pop Back\n";
        std::cout << "5. Front\n";
        std::cout << "6. Back\n";
        std::cout << "7. Insert\n";
        std::cout << "8. Remove\n";
        std::cout << "9. Find\n";
        std::cout << "10. If the Stack is Empty or Not?\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice; // user picks from list

        switch (choice) { //making different cases depending on the user input, this will allow them to pick which funciton to execute
        case 1: {
            int value;
            std::cout << "Enter value to push front: ";
            std::cin >> value;
            list.push_front(value);
            break;
        }
        case 2: {
            int value;
            std::cout << "Enter value to push back: ";
            std::cin >> value;
            list.push_back(value);
            break;
        }
        case 3:
            list.pop_front();
            break;
        case 4:
            list.pop_back();
            break;
        case 5:
            if (!list.empty()) {
                std::cout << "Front: " << list.front() << "\n";
            }
            else {
                std::cout << "List is empty.\n";
            }
            break;
        case 6:
            if (!list.empty()) {
                std::cout << "Back: " << list.back() << "\n";
            }
            else {
                std::cout << "List is empty.\n";
            }
            break;
        case 7: {
            size_t index;
            int value;
            std::cout << "Enter index to insert at: ";
            std::cin >> index;
            std::cout << "Enter value to insert: ";
            std::cin >> value;
            list.insert(index, value);
            break;
        }
        case 8: {
            size_t index;
            std::cout << "Enter index to remove: ";
            std::cin >> index;
            if (list.remove(index)) {
                std::cout << "Item removed successfully.\n";
            }
            else {
                std::cout << "Invalid index.\n";
            }
            break;
        }
        case 9: {
            int value;
            std::cout << "Enter value to find: ";
            std::cin >> value;
            size_t position = list.find(value);
            if (position < list.size()) {
                std::cout << "Item found at position: " << position << "\n";
            }
            else {
                std::cout << "Item not found in the list.\n";
            }
            break;
        }

        case 10: {
            if (!list.empty()) {
                std::cout << "Stack is not empty! \n";
            }
            else
            {
                std::cout << "Stack is empty\n";

            }
            break; 
        }
        case 0:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
        list.display();
    } while (choice != 0);

    return 0;
}