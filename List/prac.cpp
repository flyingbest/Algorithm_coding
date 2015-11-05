#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
};

void initNode(struct Node *head, int n){
	head->data = n;
	head->next = NULL;
}

void addNode(struct Node *head, int n){
	Node *newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;
	
	Node *cur = head;
	while(cur){
		if(cur->next == NULL){
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

bool deleteNode(struct Node **head, Node *ptrDel){
	Node *cur = *head;
	if(ptrDel == *head){
		*head = cur->next;
		delete ptrDel;
		return true;
	}
	

void print(struct Node *head){
	Node *list = head;
	while(list){
		cout << list->data << " ";
		list = list->next;
	}
	cout << endl;
}

int main(){
	struct Node *head = new Node;

	initNode(head, 10);
	addNode(head, 10);
	print(head);

	return 0;
}

