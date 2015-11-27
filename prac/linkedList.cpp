#include <iostream>
using namespace std;

typedef struct node{
	int data;
	struct node* next;
}	Node;

void display(Node* head){
	Node* list = head;
	if(list == NULL){
		cout << "list is empty!" << endl;
	}
	while(list){ 
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
}

void initNode(Node* head, int data){
	head->data = data;
	head->next = NULL;
}

void addNode(Node* head, int data){
	Node* newNode = new Node;
	newNode->data = data;
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

void addFront(Node** head, int data){
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}

Node* searchNode(Node* head, int data){
	Node* cur = head;
	while(cur){
		if(cur->data == data){
			cout << "Found!" << endl;
			return cur;
		}
		cur = cur->next;
	}
	cout << "NOT Found!" << endl;
}

bool deleteNode(Node** head, Node* ptrDel){
	Node* cur = *head;
	if(ptrDel == *head){
		*head = ptrDel->next;
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

int main(){
	Node* head = new Node;
	
	initNode(head, 20);	display(head);
	addFront(&head, 10); addNode(head, 30); addNode(head, 40); addNode(head, 50);
	display(head);

	int num;

	//	while(true){

	cout << "Enter the number that you deleted : ";
	cin >> num;
	
	Node* ptrDel = searchNode(head, num);
	
	if(deleteNode(&head, ptrDel))
		cout << "delete completed!" << endl;
	else
		cout << "delete failed!" << endl;

	display(head);

	//	}
 

	return 0;
}
