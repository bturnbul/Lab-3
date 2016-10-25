// LLHuff.hpp
#include <string>
#include "LLNode.hpp"
#include "LLPQ.hpp"
#ifndef LLHuff_HPP
#define LLHuff_HPP
using namespace std;

class LLHuff {
	friend class LLPQ;
	friend class LLNode;
	string file;
	LLNode *root;
	int size;
public:
	LLPQ *pq;
	LLPQ *ascii;
	LLHuff(string f);
	~LLHuff();
	void makeHuff(LLPQ *pq);
	void findCode(LLNode *root, int path);
	void readFile();
	void compressFile();
	void ReadAscii();
};

#endif //LLHuff_HPP
