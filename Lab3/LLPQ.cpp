// LLPQ.cpp

#include "LLPQ.hpp"
#include "LLNode.hpp"
#include <iostream>
#include <string>
using namespace std;

LLPQ::LLPQ() {
	first = NULL;
	size = 0;
} // LLPQ

LLPQ::~LLPQ() {
	LLNode *tmp = first;
	while (first != NULL) {
		tmp = first->next;
		delete first;
		first = tmp;
		size--;
	} // while
	first = NULL;
} // ~LLPQ

void LLPQ::printLLPQ() {
	LLNode * tmp = first;
	while (tmp != NULL) {
		cout << tmp->data << "->";
		tmp = tmp->next;
	} // while
	cout << endl;
} // printLLPQ

void LLPQ::addFirst(char x, string co) {
	co = "";
	LLNode *n = new LLNode(x);
	first = n;
	n->code = co;
	n->count += 1;
	size++;
} // addFirst

void LLPQ::addAtFirst(char x, string co) {
	co = "";
	if (first == NULL) {
		LLNode *n = new LLNode(x);
		n->code = co;
		n->count += 1;
		first = n;
		size++;
	} // if
	else {
		LLNode *tmp = new LLNode(x);
		tmp->code = co;
		tmp->count += 1;
		tmp->next = first;
		first = tmp;
		tmp->prev = NULL;
		size++;
	} // else
} // addAtFirst

LLNode *LLPQ::remFirst() {
	LLNode *tmp = first;
	if (first == 0) {
		return NULL;
	} // if
	else {
		first = tmp->next;
		first->prev = NULL;
		size--;
		return tmp;
	} // else
} // remFirst

string LLPQ::findCode(char k) {
	LLNode *tmp = first;
	string foundCode = "";
	while (tmp != NULL) {
		if (tmp->data == k) {
			foundCode = tmp->code;
			break;
		} // if
		else {
			tmp = tmp->next;
		} // else
	} // while
	return foundCode;
} // findCode

void LLPQ::sortLL() {
	for (int i = 0; i < size; i++) {
		LLNode *tmp = first;
		for (int j = 0; j < (size - 1) - i; j++) {
			if (tmp->count > tmp->next->count) {
				string tmpCode = tmp->code;
				tmp->code = tmp->next->code;
				tmp->next->code = tmpCode;
			} // if
			tmp = tmp->next;
		} // for j
	} // for i
} // sortLL

void LLPQ::insertUnique(char c) {
	// Inserts only unique characters into the linked list. If the
	// character is already in the list, it increases the count
	// of that character.
	if (findCode(c) == "") {
		if (first == NULL) {
			LLNode *n = new LLNode(c);
			n->data = c;
			n->count += 1;
			first = n;
			size++;
		} // if
		else {
			LLNode *tmp = new LLNode(c);
			tmp->count += 1;
			tmp->data = c;
			tmp->next = first;
			first = tmp;
			tmp->prev = NULL;
			size++;
		}
	}
	else {
		LLNode *tmp = first;
		for (int i = 0; i < size; i++) {
			if (tmp->data == c) {
				tmp->count += 1;
				tmp = tmp->next;
			}
			else {
				tmp = tmp->next;
			}
		}
	}
}

void LLPQ::insertInOrder(LLNode *n) {
	// Inserts the node n into the linked list in order of its
	// count value - this will be used in the creation of the
	// Huffman code.
	LLNode *tmp = first;
	int marker = n->count;
	while (tmp->count < marker) {
		tmp = tmp->next;
	}
	n->next = tmp;
	if (tmp->prev == NULL) {
		tmp->prev->next = n;
	}
	tmp->prev = n;
	size += 1;
}














