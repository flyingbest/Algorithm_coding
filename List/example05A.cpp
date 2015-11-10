/*
	This code has the following

	1. Adding Nodes;
	2. Function returning the size of the list
	3. Making the list circular (loop)
	4. Detecting circular list
	5. Recursive printing

*/

#include <iostream>
using namespace std;

typedef struct node{
	int data;
	struct node* next;
} Node;

Node* root = NULL;

void addNode(int n){
	if(root == NULL){
		root = new Node;
		root->data = n;
		root->next = NULL;
		return;
	}
	Node *cur = root;
	while(cur){
		if(cur->next == NULL){
			Node *ptr = new Node;
			ptr->data = n;
			ptr->next = NULL;
			cur->next = ptr;
			return;
		}
		cur = cur->next;
	}
}

void makeCircular(){
	if(!root || !root->next) return;
	Node* cur = root;
	while(cur){
		if(cur->next == NULL){
			cur->next = root;
			return;
		}
		cur = cur->next;
	}
}

int sizeOfList(){
	Node* cur = root;
	int size = 0;
	while(cur){
		size++;
		if(cur->next == NULL){
			return size;
		}
		cur = cur->next;
	}
	return size;
}

bool detectCircular(){
	// Assuming the list may not be circular
	
	if(!root || !root->next) return false;
	Node* ptr1 = root;
	Node* ptr2 = root;

	while(ptr1 && ptr2){
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		if(ptr2){
			ptr2 = ptr2->next;
			if(!ptr2) return false;
		}else{
			return false;
		}
		cout << ptr1->data << ", " << ptr2->data << endl;
		if(ptr1 == ptr2){
			return true;
		}
	}
	return false;
}

void printRecursive(Node* ptr){
	if(!ptr){
		cout << endl;
		return;
	}
	cout << ptr->data << " ";
	printRecursive(ptr->next);
}

int main(){
	addNode(10); addNode(20); addNode(30); addNode(40); addNode(50);
	addNode(60); addNode(70); addNode(80); addNode(90); addNode(100);

	printRecursive(root);

	cout << "size of list = " << sizeOfList() << endl;

	makeCircular();
	
	if(detectCircular()) cout << "Circular!\n";
	else cout << "Normal\n";

}

