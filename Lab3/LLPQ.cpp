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
				char tmpData = tmp->data;
				string tmpCode = tmp->code;
				int tmpCount = tmp->count;
				tmp->data = tmp->next->data;
				tmp->code = tmp->next->code;
				tmp->count = tmp->next->count;
				tmp->next->data = tmpData;
				tmp->next->code = tmpCode;
				tmp->next->count = tmpCount;
			} // if
			tmp = tmp->next;
		} // for j
	} // for i
} // sortLL

void LLPQ::insertUnique(char c) {
	// Inserts only unique characters into the linked list. If the
	// character is already in the list, it increases the count
	// of that character.
	int x = 0;
	LLNode * tmp = first;
	while (tmp != NULL) {
		if (tmp->data == c) {
			x += 1;
		}//if
			tmp = tmp->next;
	}//while
	if (x == 0) {
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
		}//else
	}//if
	else {
		LLNode *tmp = first;
		for (int i = 0; i < size; i++) {
			if (tmp->data == c) {
				tmp->count += 1;
				tmp = tmp->next;
			}//if
			else {
				tmp = tmp->next;
			}//else
		}//for
	}//else
}//insertUnique

void LLPQ::insertInOrder(LLNode *n) {
	if (first == NULL) {
		first = n;
	}//if
	else {
		LLNode * mark = first;
		while (mark->next != NULL && mark->count < n->count) {
			mark = mark->next;
		}//while
		n->next = mark->next;
		n->prev = mark;
		mark->next = n;
		if (n->next != NULL) {
			n->next->prev = n;
		}//if
	}//else
}//insertInOrder

LLPQ * LLPQ::test() {
	LLPQ * pq = new LLPQ;

	LLNode * d = new LLNode('d');
	LLNode * g = new LLNode('g');
	LLNode * f = new LLNode('f');
	LLNode * e = new LLNode('e');
	d->next = e;
	d->prev = NULL;
	d->count = 3;

	e->next = f;
	e->prev = d;
	e->count = 1;

	f->next = g;
	f->prev = e;
	f->count = 2;

	g->next = NULL;
	g->prev = f;
	g->count = 4;
	g->code = "101";

	pq->first = d;
	pq->size = 4;
	return pq;
}//test

LLNode * LLPQ::testNode() {
	LLNode * a = new LLNode('a');
	a->count = 5;
	a->code = "";
	return a;
}//testNode













