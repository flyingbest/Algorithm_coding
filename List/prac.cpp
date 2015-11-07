#include <iostream>
using namespace std;

typedef struct node{
	int data;
	struct node *next;
} Node;

void initNode(Node *head, int n){
	head->data = n;
	head->next = NULL;
}

void addNode(Node *head, int n){
	Node *newNode = new Node;
	
}


void display(Node *head){
	Node *list = head;
	while(list){
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
}	

int main(){
	Node *head = new Node;
	
	initNode(head, 10);
	display(head);
	
	return 0;
}
