// LLHuff.cpp

#include "LLNode.hpp"
#include "LLHuff.hpp"
#include "LLPQ.hpp"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
using namespace std;

LLHuff::LLHuff(string f) {
	file = f;
	root = NULL;
	size = 0;
}//LLHuff

// LLHuff::~LLHuff() {
//	    remove(root);
// }//destructor
//
//void LLHuff::remove(LLNode* root){
//     if (root == NULL) return;
//     remove(root->left);
//     remove(root->right);
//     delete root;
// }//remove


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
	}//while
	root = tmp;
}//makeHuff

void LLHuff::testHuff() {
	cout << "root = " << root->data;
	cout << ":" << root->count << endl;
	cout << "root left = " << root->left->data;
	cout << ":" << root->left->count << endl;
	cout << "root right = " << root->right->data;
	cout << ":" << root->right->count << endl;
}//testHuff

void LLHuff::findCode(LLNode *root, string path) {
	if (root == NULL) {
		return;
	}//if
	if (root->data != '$') {
		cout << root->data << ": " << path << "\n";
	}//if

	findCode(root->left, path + "0");
	findCode(root->right, path + "1");
}//findCode

void LLHuff::storeCode(LLNode *root, string path){
	if (root == NULL) {
		return;
	}//if
	if (root->data != '$') {
		root->code = path;
	}//if
	storeCode(root->left, path + "0");
	storeCode(root->right, path + "1");
}//storeCode

LLNode * LLHuff::getRoot() {
	return root;
}//getRoot

void LLHuff::readFile() {
	ifstream infile(file.c_str(), ios::in);     // open file
	char k;
	while (infile.get(k)) {     // loop getting single characters
		pq->insertUnique(k);     // inserting the character k into the priority queue
	}//while
	infile.close();
}//readFile

void LLHuff::readAscii() {
	cout << file << endl;
	ifstream infile("asciitable.txt", ios::in);
	char ch;
	string asciicode;
	if (!infile.is_open()) {
		return;
	}//if
	infile >> asciicode;
	pq->addFirst(' ', asciicode);
	infile >> asciicode;
	while (infile>>ch) {
		cout << ch;
		infile>>asciicode;
		cout << asciicode << endl;
		pq->addAtFirst(ch, asciicode);
	}//while
	cout << endl;
	infile.close();
	////////////////////////////
	ifstream infile2(file.c_str(), ios::in);
	ofstream outfile("asciivsn.txt", ios::out);
	char k;
	string comp;
	while (infile2.get(k)) {
		cout << k;
		comp = pq->findCode(k);
		if (comp == "") {
			cout << "ERROR WITH " << k << endl;
		}//if
		else {
			cout << k << ":" << comp << endl;
			outfile << comp << " ";
		}//else
	}//while
	cout << endl;
	infile2.close();
	outfile.close();
}//readAscii

void LLHuff::compressFile(){
	ifstream infile(file.c_str(), ios::in);
	ofstream outfile("compressed.txt", ios::out);
	char k;
		string comp;
		while (infile.get(k)) {
			cout << k;
			comp = pq->findCode(k);
			if (comp == "") {
				cout << "ERROR WITH " << k << endl;
			}//if
			else {
				cout << k << ":" << comp << endl;
				outfile << comp << " ";
			}//else
		}//while
		cout << endl;
		infile.close();
		outfile.close();

}//compressFile




