#include <iostream>
using namespace std;

typedef struct node{
	int data;
	struct node* next;
}	Node;

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
		if(cur->data == n)	return cur;
		cur = cur->next;
	}
	cout << "No Node " << n << " in the list.\n";
}

bool deleteNode(Node** head, Node* ptrDel){
	Node* cur = *head;
	if(ptrDel == *head){
		*head = cur->next;
		delete ptrDel;
		return true;
	}
	while(cur){
		if(cur->next == ptrDel){
			cur->next = ptrDel->next;
			delete ptrDel;
			return true;
		}
		cur = cur->next;
	}
	return false;
}



void display(Node* head){
	Node* list = head;
	while(list){
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
}

int main(){
	Node* head = new Node;
	
	initNode(head, 20);
	display(head);
	addNode(head, 30);
	display(head);
	addNode(head, 40);
	display(head);
	addFront(&head, 10);
	display(head);
	addFront(&head, 5);
	display(head);
	Node* ptrDel = searchNode(head, 7);
	ptrDel = searchNode(head, 10);
		
	display(head);
	return 0;
}

