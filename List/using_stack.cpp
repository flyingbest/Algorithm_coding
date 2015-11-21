#include <iostream>
using namespace std;

typedef struct element{
	void* data;
	struct element* next;
} Element;

bool push(Element** top, void* data){
	Element* elem = new Element;
	if(!elem) return false;

	elem->data = data;
	elem->next = *top;
	*top = elem;
	return true;
}

bool createStack(Element** top){
	*top = NULL;
	return true;
}

bool pop(Element** top, void** data){
	Element* elem;
	if( !(elem = *top) ) return false;
	
	*data = elem->data;
	*top = elem->next;
	delete elem;
	return true;
}

bool deleteStack(Element** top){
	Element* elem;
	while(*top){
		elem = (*top)->next;
		delete *top;
		*top = elem;
	}
}

void printStack(Element* top){
	if(top == NULL){
		cout << "Empty!" << endl;
	}
	Element* cur = top;
	while(cur){
		cout << *(static_cast<int*>(cur->data)) << " ";
		cur = cur->next;
	}
	cout << endl << endl;
}

int main(){
	Element* head;
	createStack(&head);
	//int n[5] = {10, 20, 30, 40, 50};
	int n1 = 10, n2 = 20, n3 = 30, n4 = 40, n5 = 50;
	
	push(&head, &n1);
	push(&head, &n2);
	push(&head, &n3);
	push(&head, &n4);
	push(&head, &n5);

	printStack(head);

	void* n;
	pop(&head, &n);
	cout << "popped " << *(static_cast<int*>(n)) << endl;
	pop(&head, &n);
	cout << "popped " << *(static_cast<int*>(n)) << endl;
	cout << endl;

	printStack(head);

	cout << "deleting stack..." << endl;
	deleteStack(&head);
	printStack(head);

	return 0;
}

