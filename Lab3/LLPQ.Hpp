// LLPQ.hpp

#ifndef LLPQ_HPP
#define LLPQ_HPP
#include "LLNode.hpp"
#include <string>

using namespace std;

class LLPQ {
	friend class LLHuff;
	friend class LLNode;
	LLNode * first;
	int size;
public:
	LLPQ();
	~LLPQ();
	void printLLPQ();
	void addFirst(char x, string co);
	void addAtFirst(char x, string co);
	LLNode * remFirst();
	string findCode(char k);
	void sortLL();
	void insertUnique(char c);
	void insertInOrder(LLNode *n);
	LLPQ * test();
	LLNode * testNode();
};

#endif /* LLPQ_HPP */
