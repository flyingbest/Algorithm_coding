#include <iostream>
using namespace std;

typedef struct node{
	int data;
	struct node* next;
	struct node* prev;
} Node;

void printFront(Node* head){
	Node* list = head;
	while(list){
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
}

void printReverse(Node* tail){
	Node* list = tail;
	while(list){
		cout << list->data << " ";
		list = list->prev;
	}
	cout << endl;
}

void initNode(Node* head, Node** tail, int n){
	head->data = n;
	head->next = NULL;
	head->prev = NULL;
	*tail = head;
}

void addNode(Node* head, Node** tail, int n){
	Node* newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	Node* cur = head;
	while(cur){
		if(cur->next == NULL){
			cur->next = newNode;
			newNode->prev = *tail;
			*tail = newNode;
			return;
		}
		cur = cur->next;
	}
}

void addFront(Node** head, int n){
	Node* newNode = new Node;
	newNode->data = n;
	newNode->next = *head;
	(*head)->prev = newNode;
	*head = newNode;
	newNode->prev = NULL;
}



int main(){
	Node* head = new Node;
	Node* tail = new Node;

	initNode(head, &tail, 2);
	printFront(head);
	printReverse(tail);

	addNode(head, &tail, 4);
	printFront(head);
	printReverse(tail);

	addNode(head, &tail, 8);
	printFront(head);
	printReverse(tail);

	addFront(&head, 1);
	printFront(head);
	printReverse(tail);

	addNode(head, &tail, 16);
	printFront(head);
	printReverse(tail);




	return 0;
}

