#include "BSTSet.h"
#include <iostream>
#include <vector>
using namespace std;

BSTSet::BSTSet()
{
	root = NULL;
}

BSTSet::BSTSet(const std::vector<int>& input)
{
	bool prevdirection = false; //used to determine direction of the prev node traveled
	if (input.size() > 0) {
		root = new TNode(input[0], NULL, NULL); //first thing in input is the root
		TNode* current = root;
		TNode* prev = root;
		for (int i = 1; i < input.size(); i++) { //for is inserting everything else in the input
			while (current!=NULL && current->element!=input[i]) { //while is finding the spot to insert it
				if (current->element > input[i]) { //taking it left
					prev = current;
					current = current->left;
					prevdirection = false;
				}
				else if (current->element < input[i]) { //taking it right
					prev = current;
					current = current->right;
					prevdirection = true;
				}
			}
			if (current==NULL && prevdirection) { //inserts to the right of previous node
				prev->right = new TNode(input[i], NULL, NULL);
			}
			if (current == NULL && !prevdirection) { //inserts to the left of previous node
				prev->left = new TNode(input[i], NULL, NULL);
			}
			current = root; //resets current and prev so each new addition starts from the root
			prev = root;
		}
	}
}


BSTSet::~BSTSet()
{
	// TODO
}
bool BSTSet::isInRec(TNode* t, int v){
    if(root == NULL){
        return false;
    }
    if(t->element == v){
        return true;
    }else if((t->left==NULL && t->element > v) ||(t->right==NULL && t->element < v)){
        return false;
    }else{
        if(v < t->element){
            return isInRec(t->left, v);
        }else{
            return isInRec(t->right, v);
        }
    }
}

bool BSTSet::isIn(int v)
{
    return isInRec(root, v);
    /*
	TNode* t = root;
    while(t!=NULL){
        if(v == t->element){
            return true;
        }else if(v < t->element){
            t = t->left;
        }else{
            t=t->right;
        }
    }
    return false;

    */
}

void BSTSet::add(int v)
{/*
    TNode* t = root;
    if(root == NULL){
        root = new TNode(v,NULL,NULL);
    }
    if(!isIn(v)){
	while(t!=NULL){
                
        if(v < t->element && t->left!=NULL){
            t = t->left;
        }else if(v < t->element && t->left==NULL) {
            t->left = new TNode(v, NULL,NULL);
        }else if(v > t->element && t->right!=NULL){
            t=t->right;
        }else{
            t->right = new TNode(v, NULL,NULL);
        }
    }
    }*/
}

bool BSTSet::remove(int v)
{
	// TODO
    return true; //change this after completing this function
}

void BSTSet::Union(const BSTSet& s)
{
	// TODO
}

void BSTSet::intersection(const BSTSet& s)
{
	// TODO
}

void BSTSet::difference(const BSTSet& s)
{
	// TODO
}

int BSTSet::size()
{
	// TODO
    return -1; //change this after completing this function
}

int BSTSet::height()
{
	// TODO
    return -2; //change this after completing this function
}

// create and use class MyStack
void BSTSet::printNonRec()
{
	// TODO
	cout << "-2"; //change this after completing this function
}

// Do not modify following provided methods

void BSTSet::printBSTSet()
{
    if (root == NULL)
        std::cout << "";
    else {
        printBSTSet(root);
    }
}

void BSTSet::printBSTSet(TNode* t)
{
    if (t != NULL) {
        printBSTSet(t->left);
        std::cout << t->element << ",";
        printBSTSet(t->right);
    }
}
