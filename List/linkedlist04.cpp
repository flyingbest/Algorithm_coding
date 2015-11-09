#include <iostream>
using namespace std;

typedef struct node{
	int data;
	struct node* next;
}	Node;

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
			cout << "Data < " << n << " > in this list.\n";
			return cur;
		}
		cur = cur->next;
	}
	cout << "Data < " << n << " > not in this list.\n";
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
			cur->next =	ptrDel->next;
			delete ptrDel;
			return true;
		}
		cur = cur->next;
	}
	return false;
}




int main(){
	Node* head = new Node;
	
	initNode(head, 20);
	printlist(head);
	addFront(&head, 10);
	printlist(head);
	addNode(head, 30);
	printlist(head);
	addNode(head, 40);
	printlist(head);
	addNode(head, 50);
	printlist(head);

	int num = 10;
	Node* ptrDel = searchNode(head, num);
	
	if(deleteNode(&head, ptrDel))
		cout << "delete complete!\n";
	else
		cout << "delete failed!\n";
	printlist(head);
	cout << endl;
	
	ptrDel = searchNode(head, 25);
	if(deleteNode(&head, ptrDel))
		cout << "delete complete!\n";
	else
		cout << "delete failed!\n";
	printlist(head);
	cout << endl;

		
	
	
	return 0;
}
