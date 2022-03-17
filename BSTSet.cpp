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
    root = NULL;
    if(input.size() > 0){
        for(int i = 0; i < input.size(); i++){
        if(!isIn(input[i])){
            add(input[i]);
        }
        }
    }
    /*
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
	}*/
}


BSTSet::~BSTSet()
{
	deleteRec(root);
}

void BSTSet::deleteRec(TNode* t){
    if(t!=NULL){
        deleteRec(t->left);
        deleteRec(t->right);
        free(t);
    }
}

bool BSTSet::isInRec( TNode* t, int v) const{
    if(t == NULL){
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
}

void BSTSet::addRec(TNode* t, int v){
    if (root == NULL){
        root = new TNode(v,NULL,NULL);
    }else if(!isIn(v)){
        if(v<t->element && t->left == NULL){
            t->left = new TNode(v,NULL,NULL);
        }else if(v>t->element && t->right == NULL){
            t->right=new TNode(v,NULL,NULL);
        }else{
            if(v < t->element){
                addRec(t->left, v);
            }else{
            return addRec(t->right, v);
        }
        }
    }
}

void BSTSet::add(int v)
{
    addRec(root, v);
}

void BSTSet::removeRec(TNode* &t, int v){
    if(t==NULL){
        return;
    }if(v< t->element){
        removeRec(t->left, v);
    }else if(v > t->element){
        removeRec(t->right, v);
    }else if(t->left!=NULL &&t->right!=NULL){//two kids
        t->element = min(t->right)->element;
        removeRec(t->right, t->element);
    }else{
        TNode* oldNode = t;
        t = (t->left != NULL)? t->left : t->right;
        delete t;
    }

    
}
bool BSTSet::remove(int v)
{
    bool ret = isIn(v);
    if(ret){
        removeRec(root, v);
    }
	
	
    return ret; 
}
TNode* BSTSet::min(TNode * t){
    
    while(t->left!=NULL){
        t=t->left;
    }
    return t;
}

std::vector<int> BSTSet::lists(std::vector<int> &in, TNode* t) const{
    if(t!=NULL){
        lists(in, t->left);
        in.push_back(t->element);
        lists(in, t->right);
    }

}

void BSTSet::UnionRec(TNode* t){
    if(t!=NULL){
        UnionRec(t->left);
        add(t->element);
        UnionRec(t->right);
    }
}

void BSTSet::Union(const BSTSet& s)
{
	UnionRec(s.root);
}

void BSTSet::intersecionRec( TNode*& t1, TNode*& t2){


    if(t1 !=nullptr){
        
        if(!isInRec(t2, t1->element)){
          
            removeRec(t1, t1->element);
            intersecionRec(t1,t2);
        }else{
            intersecionRec(t1->left,t2);
            intersecionRec(t1->right,t2);
        }
    }
}

void BSTSet::intersection(const BSTSet& s)
{
    
    TNode* input = s.root;
	intersecionRec(root, input); 
}
void BSTSet::diffRec(TNode* t){
    if(t!=NULL){
        diffRec(t->left);
        if(isIn(t->element)){remove(t->element);}
        diffRec(t->right);
    }
}

void BSTSet::difference(const BSTSet& s)
{

	diffRec( s.root); 
}
int BSTSet::sizeRec(TNode* t){
    if(t==NULL){
        return 0;
    }else{
        return(sizeRec(t->left) + sizeRec(t->right) +1);//every node traversed adds one
    }
}

int BSTSet::size()
{
	
    return sizeRec(root); //change this after completing this function
}
int BSTSet::heightRec(TNode* t){
    if(t==NULL){
        return -1;
    }else{
        int r = heightRec(t->right);
        int l = heightRec(t->left);

        if(r>l){
            return r + 1;
        }else{
            return l + 1;
        }
    }
}

int BSTSet::height()
{
	// TODO
    return heightRec(root); //change this after completing this function
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
