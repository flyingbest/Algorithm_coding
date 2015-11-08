#include <iostream>
using namespace std;

typedef struct node{
	int data;
	struct node* next;
} Node;

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
			cout << "Found!!!\n";
			return cur;
		}
		cur = cur->next;
	}
	cout << "No match data in this list\n";
}	

bool deleteNode(Node** head, Node* ptrDel){
	Node* cur = *head;
	if(ptrDel == *head){
		ptrDel->next = *head;
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

void print(Node* head){
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
	print(head);
	addNode(head, 30);
	print(head);
	addFront(&head, 10);
	print(head);
	addNode(head, 40);
	addNode(head, 50);
	print(head);

	cout << "==============================\n";
	
	Node* ptrDel = searchNode(head, 10);
	cout << "found num : " << ptrDel->data << endl;
	print(head);

	cout << "==============================\n";

	int Delnum = 20;
	ptrDel = searchNode(head, Delnum);
	if(deleteNode(&head, ptrDel)){
		cout << "delete complete!\n";
	}
	print(head);

	return 0;
}
