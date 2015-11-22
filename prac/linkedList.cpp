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
		list = list->next;
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
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

void addFront(Node** head, int n){
	Node* newNode = new Node;
	newNode->data = n;
	newNode->next = *head;
	*head = newNode;
}

Node* searchNode(Node* head, int n){
	Node* cur = head;
	while(cur){
		if(cur->data == n){
			cout << "Find!!" << endl;
			return cur;
		}
		cur = cur->next;
	}
	cout << "NO such DATA in this list." << endl;
}
		
bool deleteNode(Node** head, Node* ptrDel){
	Node* cur = *head;
	if(ptrDel == *head){
		*head = cur->next;
		delete ptrDel;
		return true;
	}
	while(cur){
		if(cur->next = ptrDel){
			cur->next = ptrDel->next;
			delete ptrDel;
			return true;
		}
		cur = cur->next;
	}
	return false;
}

int main(){
	Node* head = new Node;
	
	initNode(head, 10);	printlist(head);
	addNode(head, 20); printlist(head);
	addFront(&head, 5);	printlist(head);
	addNode(head, 30); printlist(head);
	addFront(&head, 1);	printlist(head);

	int Del = 25;
	Node* ptrDel = searchNode(head, Del);	// NOT exist data.
	ptrDel = searchNode(head, 20);	// exist data.

	printlist(head);

	if(deleteNode(&head, ptrDel))
		cout << "delete complete!!!" << endl;
	else
		cout << "delete failed!!!" << endl;

	printlist(head);

	return 0;
}

