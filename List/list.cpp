// linked list

#include <iostream>
using namespace std;

typedef struct node{
	char data[20];
	struct node* next;
} Node;

void printlist(Node* head){
	Node* list = head;
	while(list){
		cout << list->data << " ";

