#include <iostream>
#include <stdlib.h>
#include "LLNode.hpp"
#include "LLHuff.hpp"
#include "LLPQ.hpp"
using namespace std;


int main() {
	cout << "-----------------------------------" << endl;
	cout << "LLPQ Tests" << endl << endl;
	LLPQ * pq = new LLPQ();
	LLPQ * tst = pq->test();

	cout << "printLLPQ" << endl;
	tst->printLLPQ();
	cout << endl;

	cout << "addFirst" << endl;
	LLPQ * pq2 = new LLPQ();
	pq2->addFirst('c', "");
	pq2->printLLPQ();
	cout << endl;

	cout << "addAtFirst" << endl;
	tst->addAtFirst('c', "");
	tst->printLLPQ();
	cout << endl;

	cout << "remFirst" << endl;
	tst->remFirst();
	tst->printLLPQ();
	cout << endl;

	cout << "findCode" << endl;
	cout << tst->findCode('g');
	cout << endl << endl;

	cout << "sortLL" << endl;
	tst->sortLL();
	tst->printLLPQ();
	cout << endl;

	cout << "insertUnique" << endl;
	tst->insertUnique('r');
	tst->printLLPQ();
	tst->insertUnique('r');
	tst->printLLPQ();
	cout << endl;

	cout << "insertInOrder" << endl;
	LLNode * a = tst->testNode();
	tst->sortLL();
	tst->insertInOrder(a);
	tst->printLLPQ();

	cout << endl << "-----------------------------------" << endl;
	cout << "LLHuff Tests" << endl << endl;

	cout << "makeHuff" << endl;
	LLHuff * tstH = new LLHuff("testFile");
	tstH->makeHuff(tst);
	tstH->testHuff();
	cout << endl;

	cout << "findCode" << endl;
	LLNode * tstHRoot = tstH->getRoot();
	tstH->findCode(tstHRoot, "");
	cout << endl;

	cout << "reading file" << endl;
	LLHuff code("tests.txt");
	code.readFile();
	code.pq->printLLPQ();
	code.pq->sortLL();
	code.pq->printLLPQ();
	code.makeHuff(pq);
	code.compressFile();
	code.readAscii();
	return 0;


  	return 0;
}

