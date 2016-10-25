// LLNode.hpp

#ifndef LLNode_HPP
#define LLNode_HPP
#include <string>

using namespace std;

class LLNode {
	friend class LLPQ;
	friend class LLHuff;
	char data;
	LLNode *next;
	LLNode *prev;
	LLNode *right;
	LLNode *left;
	int count; // number of occurrences of character
	string code; // code generated for character
public:
	LLNode(char k);
	~LLNode();
	char getData();
};

#endif /* LLNode_HPP */
