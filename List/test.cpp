#include <iostream>
#include <cstdlib>
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

Node* searchNode(Node* head, int n){
	Node* cur = head;
	while(cur){
		if(cur->data == n){
			cout << "Node < " << n << " > exist in this list.\n";
			return cur;
		}
		cur = cur->next;
	}
	cout << "Node < " << n << " > NOT exist in this list.\n";
}

bool deleteNode(Node** head, Node** tail, Node* ptrDel){
	Node* cur = *head;
	if(ptrDel == *head){
		*head = cur->next;
		(*head)->prev = NULL;
		delete ptrDel;
		return true;
	}
	Node* tmp = NULL;
	while(cur){
		if(cur->next == ptrDel){
			cur->next = ptrDel->next;
			if(ptrDel->next != NULL){
				tmp = ptrDel->next;
				tmp->prev = cur;
			}else{
				*tail = cur;
			}
			delete ptrDel;
			return true;
		}
		cur = cur->next;
	}
	return false;
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

