#include "Bag.h"
#include "BagIterator.h"
#include <exception>
#include <iostream>
using namespace std;


Bag::Bag() {
	head = nullptr;
	tail = nullptr;
	nr_of_elements = 0;
}


void Bag::add(TElem elem) {
	Node* newNode = new Node(elem);
	if (search(elem) == true) {
		Node* current_node = head;
		while (current_node != nullptr && current_node->element != elem) {
			current_node = current_node->next;
		}
		current_node->frequency++;
	
	}
	else {
		newNode->frequency = 1;
		newNode->next = nullptr;
		newNode->previous = tail;
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	nr_of_elements++;

}


bool Bag::remove(TElem elem) {
	Node* current_node = head;
	if(search(elem) == true)
	{
		if (current_node->frequency > 1) {
			current_node->frequency--;
	
		}
		else  {
			if (current_node == head) {
				if (current_node == tail)
				{
					head = nullptr;
					tail = nullptr;
				
				}
				else
				{
					head = head->next;
					head->previous = nullptr;
					
				}
			}
			else if (current_node == tail) {
				tail = tail->previous;
				tail->next = nullptr;
				
			}
			else {
				current_node->previous->next = current_node->next;
				current_node->next->previous = current_node->previous;
			}
			
		}
		nr_of_elements--;
		return true;
	}
	return false; 
}


bool Bag::search(TElem elem) const {
	Node* current_node = head;
	while (current_node != nullptr && current_node->element != elem) {
		current_node = current_node->next;
	}
	if (current_node != nullptr) {
		
		return true;
	}
	else {
		
		return false;
	}
}

int Bag::nrOccurrences(TElem elem) const {
	Node* current_node = head;
	while (current_node != nullptr && current_node->element != elem) {
		current_node = current_node->next;
	}
	if (current_node != nullptr) {
		
		return current_node->frequency;
	}
	else
		return 0;
}


int Bag::size() const {
	
	return nr_of_elements;
}


bool Bag::isEmpty() const {
	if(head == nullptr)
		return true;
	return false;
}

BagIterator Bag::iterator() const {
	return BagIterator(*this);
}


Bag::~Bag() {
	
}

