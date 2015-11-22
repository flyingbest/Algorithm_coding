#include <iostream>
#include <string>
using namespace std;

typedef struct node{
	string name;
	struct node* next;
} Node;

bool createStack(Node** top){
	*top = NULL;
	return true;
}

bool push(Node** top, string* data){
	Node* newNode = new Node;
	if(!newNode) return false;

	newNode->name = data;
	newNode->next = *top;
	*top = newNode;
	return true;
}

bool pop(Node** top, string** data){
	Node* tmp = *top;
	if(!tmp) return false;

	*data = tmp->name;
	*top = tmp->next;
	delete tmp;
	return true;
}

bool deleteStack(Node** top){
	Node* tmp;
	while(*top){
		tmp = (*top)->next;
		delete *top;
		*top = tmp;
	}
}

void printStack(Node* top){
	if(top == NULL){
		cout << "Empty!" << endl;
	}
	Node* cur = top;
	while(cur){
		cout << *(static_cast<string*>(cur->name)) << " ";
		cur = cur->next;
	}
	cout << endl << endl;
}

int main(){
	Node* head;
	createStack(&head);
	
	string n1 = "what", n2 = "is", n3 = "your", n4 = "dream?", n5 = "son";

	push(&head, &n1);
	push(&head, &n2);
	push(&head, &n3);
	push(&head, &n4);
	push(&head, &n5);

	printStack(head);

	void* n;
	pop(&head, &n);
	cout << "popped " << *(static_cast<string*>(n)) << endl;
	pop(&head, &n);
	cout << "popped " << *(static_cast<string*>(n)) << endl;
	cout << endl;

	printStack(head);

	cout << "deleting stack..." << endl;
	deleteStack(&head);
	printStack(head);

	return 0;
}
