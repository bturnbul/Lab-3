#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "LLNode.hpp"
#include "LLHuff.hpp"
using namespace std;


int main() {
	cout << "reading file" << endl;
	LLHuff code("tests.txt");
	cout << "reading file" << endl;
	code.readFile();
	cout << "reading file" << endl;
	code.pq->printLLPQ();
	cout << "reading file" << endl;
	code.pq->sortLL();
	code.pq->printLLPQ();
	code.makeHuff(code.pq);
	//code.compressFile();
	code.ReadAscii();

  	return 0;
}
