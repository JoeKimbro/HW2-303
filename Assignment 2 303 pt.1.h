#pragma once
#include <iostream>
#include <vector>

template<typename Item_Type>
class Node {
public:
	Item_Type data;
	Node* next;

	Node(const Item_Type& data) : data(data), next(nullptr) {}
};

template<typename Item_Type>
class linked_list {
private:
	Node<Item_Type>* head;
	Node<Item_Type>* tail;
	size_t num_items;

public: // this is where the functions need to go so others can use
	linked_list() : head(nullptr), tail(nullptr), num_items(0) {}
	~linked_list() {
		while (head != nullptr) {
			Node<Item_Type>* temp = head;
			head = head->next;
			delete temp;
		}
		tail = nullptr;
		num_items = 0;
	}

	void push_front(const Item_Type& item) {
		Node<Item_Type>* new_node = new Node<Item_Type>(item);
		if (empty()) {
			head = tail = new_node; 
		}

		else {
			new_node->next = head; 
			head = new_node; 

		}
		num_items++;
	}


	void push_back(const Item_Type& item) {
		Node<Item_Type>* new_node = new Node<Item_Type>(item);
		if (empty()) {
			head = tail = new_node;
		}
		else {
			tail->next = new_node;
			tail = new_node;
		}
		num_items++;
	}

	void pop_front() {
		if (!empty()) {
			Node<Item_Type>* temp = head;
			head = head->next;
			delete temp;
			num_items--;

			if (empty()) {
				tail = nullptr;
			}
		}
	}

	void pop_back() {
		if (!empty()) {
			if (head == tail) {
				delete head;
				head = tail = nullptr;
			}
			else {
				Node<Item_Type>* temp = head;
				while (temp->next != tail) {
					temp = temp->next;
				}
				delete tail;
				tail = temp;
				tail->next = nullptr;
			}
			num_items--;
			if (empty()) {
				head = nullptr;
			}
		}
	}


	Item_Type front() const  {
		if (!empty()) {
			return head->data;
		}
		else
			throw std::invalid_argument("LIST IS EMPTY!!"); 
	
	}

	Item_Type back() const  {
		if (!empty()) {
			return tail->data;
		}
		else
			throw std::invalid_argument("LIST IS EMPTY!!");
	
	}

	bool empty() const {
		return num_items == 0;
	
	}

	void insert(size_t index, const Item_Type& item) {
		if (index <= num_items) {
			if (index == 0) {
				push_front(item);
			}
			else if (index == num_items) {
				push_back(item);
			}
			else {
				Node<Item_Type>* new_node = new Node<Item_Type>(item);
				Node<Item_Type>* current = head;
				for (size_t i = 1; i < index; ++i) {
					current = current->next;
				}
				new_node->next = current->next;
				current->next = new_node;
				num_items++;
			}
		}
	}


	bool remove(size_t index) {
		if (index < num_items) {
			if (index == 0) {
				pop_front();
			}
			else {
				Node<Item_Type>* current = head;
				for (size_t i = 1; i < index; ++i) {
					current = current->next;
				}
				Node<Item_Type>* temp = current->next;
				current->next = temp->next;
				delete temp;
				num_items--;
			}
			return true;
		}
		return false;
	}

	size_t find(const Item_Type& item) const {
		Node<Item_Type>* current = head;
		size_t index = 0;
		while (current != nullptr) {
			if (current->data == item) {
				return index;
			}
			current = current->next;
			index++;
		}
		return num_items; 

	}

	size_t size() const {
		return num_items;
	}

	void display() const {
		Node<Item_Type>* current = head;
		std::cout << "List: ";
		while (current != nullptr) {
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << "\n";
	}
};