#include <iostream>
using namespace std;

typedef struct node{
	int data;
	struct node* next;
} Node;

void printlist(Node* head){
	Node* list = head;
	while(list){
		cout << list->data << " ";
		list = list->data;
	}
	cout << endl;
}

void initNode(Node* head, int n){
	head->data = n;
	head->next = NULL;
}

void addNode(Node* head, int n){
	Node* newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;
	
	Node* cur = head;
	while(cur){
		if(cur->next == NULL){
			
	


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
	cout << "\n====================================\n";

	cout << "Find number 10 in the list!\n";
	int Delnum = 10;
	Node* ptrDel = searchNode(head, Delnum);
	cout << "\n====================================\n";

	cout << "Find number 16 in the list!\n";
	Delnum = 16;
	ptrDel = searchNode(head, Delnum);
	cout << "\n====================================\n";
	
	Delnum = 8;		////////// check as chage number!!!
	ptrDel = searchNode(head, Delnum);
	if(deleteNode(&head, &tail, ptrDel))
		cout << "delete complete!\n";
	else
		cout << "delete failed!\n";
	printFront(head);
	printReverse(tail);
	cout << "\n====================================\n";

	return 0;
}

