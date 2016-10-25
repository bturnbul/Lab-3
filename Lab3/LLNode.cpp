// LLNode.cpp

#include "LLNode.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

LLNode::LLNode(char k) {
	data = k;
	next = NULL;
	prev = NULL;
	right = NULL;
	left = NULL;
} // LLNode

LLNode::~LLNode() {
	if (next != NULL || prev != NULL) {
		cout << "deleting this LLNode may cause a memory leak" << endl;
	} // if
} // ~LLNode

char LLNode::getData() {
	return data;
} // getData