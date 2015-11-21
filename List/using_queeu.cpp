#include <iostream>
using namespace std;

typedef struct node{
	int data;
	struct node* next;
} Node;

Node* head = NULL;

void push(int n){
	Node* newNode = new Node;
	newNode->data = n;
	newNode->next = NULL;

	if(head == NULL){
		head = newNode;
		return;
	}

	Node* cur = head;
	while(cur){
		if(cur->next == NULL){
			cur->next = newNode;
			return;
		}
		cur = cur->next;
	}
}

void pop(){
	if(head == NULL) return;
	Node* tmp = head;
	head = head->next;
	delete tmp;
}

void display(){
	Node* cur = head;
	while(cur){
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

int main(){
	push(10);push(20);push(30);push(40);push(50);display();
	pop();display();
	pop();display();
	push(60);display();
	pop();display();
	pop();display();
	pop();display();
	pop();display();
	return 0;
}

