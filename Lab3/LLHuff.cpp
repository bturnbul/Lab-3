// LLHuff.cpp

#include "LLNode.hpp"
#include "LLHuff.hpp"
#include "LLPQ.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

 LLHuff::LLHuff(string f) {
	file = f;
	root = NULL;
	size = 0;
}

 LLHuff::~LLHuff() {
//	delete right;
//	delete left;
}

void LLHuff::makeHuff(LLPQ *pq) {
	LLNode *tmp = pq->first;
	LLNode *tmp2 = pq->first->next;
	while (pq->first->next != NULL) {
		pq->first = pq->first->next->next;
		LLNode *h = new LLNode('$');
		h->count = tmp->count + tmp2->count;
		h->left = tmp;
		h->right = tmp2;
		pq->insertInOrder(h);
		tmp = pq->first;
		tmp2 = pq->first->next;
	}
}

void LLHuff::readFile() {
	char k;
	ifstream infile(file.c_str(), ios::in);     // open file
	while (infile.get(k)) {     // loop getting single characters
		pq->insertUnique(k);     // inserting the character k into the priority queue
	}
	infile.close();
}

void LLHuff::ReadAscii() {
	cout << file << endl;
	ifstream infile("asciitable.txt", ios::in); // open file
	char ch;
	string asciicode;
	if (!infile.is_open()) {
		return;
	}
	infile >> asciicode;
	pq->addFirst(' ', asciicode);
	infile >> asciicode;
	while (infile >> ch) { // loop getting single characters
		cout << ch;
		infile >> asciicode; // gets entire word (code)
		cout << asciicode << endl;
		pq->addAtFirst(ch, asciicode);
	}
	cout << endl;
	infile.close();
/////////////////////////////////////
	ifstream infile2(file.c_str(), ios::in); // open file for reading
	ofstream outfile("asciivsn.txt", ios::out);
	char k;
	string comp;
	while (infile2.get(k)) { // loop getting single characters
		cout << k;
		comp = pq->findCode(k);
		if (comp == "") {
			cout << "ERROR WITH " << k << endl;
		} else {
			cout << k << ":" << comp << endl;
			outfile << comp << " ";
		}
	}
	cout << endl;
	infile2.close();
	outfile.close();
}





