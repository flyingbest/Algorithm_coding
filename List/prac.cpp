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

void display(Node* head){
	Node* cur = head;
	while(cur){
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main(){
	Node* head = new Node;
	
	initNode(head, 10);
	display(head);
	
	addNode(head, 20);
	display(head);
	
	return 0;
}
