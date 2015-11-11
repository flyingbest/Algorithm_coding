#include <cstdlib>
#include <iostream>
using namespace std;

struct node{
	int data;
	node* next;
	node* prev;
};

void printForward(node* head);
void printReverse(node* tail);

int main(){

	node* head;
	node* tail;
	node* n;

	n = new node;
	n->data = 1;
	n->prev = NULL;
	head = n;
	tail = n;
	
	n = new node;
	n->data = 2;
	n->prev = tail;
	tail->next = n;
	tail = n;

	n = new node;
	n->data = 3;
	n->prev = tail;
	tail->next = n;
	tail = n;

	n = new node;
	n->data = 4;
	n->prev = tail;
	tail->next = n;
	tail = n;
	tail->next = NULL;

	printForward(head);	
	printReverse(tail);

	return 0;
}

void printForward(node* head){
	node* tmp = head;
	while(tmp != NULL){
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

void printReverse(node* tail){
	node* tmp = tail;
	while(tmp != NULL){
		cout << tmp->data << " ";
		tmp = tmp->prev;
	}
	cout << endl;
}
