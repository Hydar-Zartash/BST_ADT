#ifndef BSTSET_H_
#define BSTSET_H_

#include "TNode.h"
#include <vector>

class BSTSet
{
private:
	// must contain only one private field
	TNode* root = NULL;
	void addRec(TNode* t, int v);
	bool isInRec( TNode* t, int v) const;
	int sizeRec(TNode* t);
	int heightRec(TNode* t);
	void removeRec(TNode* &t, int v);
	void UnionRec(TNode* t);
	void deleteRec(TNode* t);
	void intersecionRec(TNode*& t1, TNode*& t2) ;
	void diffRec( TNode* t);
	TNode* subTreemin(TNode* t);
	std::vector<int> lists(std::vector<int> &in, TNode* t) const;
	TNode* min(TNode* t);


public:
	// required constructors/destructor
	BSTSet();
	BSTSet(const std::vector<int>& input);
	~BSTSet();

	// required methods
	bool isIn(int v);
	void add(int v);
	bool remove(int v);
	void Union(const BSTSet& s);
	void intersection(const BSTSet& s);
	void difference(const BSTSet& s);
	int size();
	int height();
	void printNonRec(); // create and use class MyStack

	// provided recursive print method
	void printBSTSet();

	// Used for testing
	TNode* getRoot()
	{
		return root;
	}

private:
	// provided helper methods
	void printBSTSet(TNode* t);
};

#endif /* BSTSET_H_ */
