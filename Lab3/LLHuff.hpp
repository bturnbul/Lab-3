
// LLHuff.hpp

#ifndef LLHuff_HPP
#define LLHuff_HPP
#include "LLNode.hpp"
#include "LLPQ.hpp"
#include <string>
#include <iostream>

using namespace std;

class LLHuff {
	friend class LLNode;
	friend class LLPQ;
	string file;
	LLNode *root;
	int size;
	LLPQ *ascii;
public:
	LLPQ *pq;
	LLHuff(string f);
//	~LLHuff();
	void storeCode(LLNode *root, string path);
	void makeHuff(LLPQ *pq);
	void testHuff();
	LLNode * getRoot();
	void findCode(LLNode *root, string path);
	void readFile();
	void compressFile();
	void readAscii();
	void remove(LLNode* root);
};

#endif /* LLHuff_HPP */
