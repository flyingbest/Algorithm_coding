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
		if(cur->data == n){
			cout << "Found!!!\n";
			return cur;
		}
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

void copylinkedList(Node* node, Node** pNew){
	if(node != NULL){
		*pNew = new Node;
		(*pNew)->data = node->data;
		(*pNew)->next = NULL;
		copylinkedList(node->next, &((*pNew)->next));
	}
}

bool comparelinkedList(Node* node1, Node* node2){
	if(node1 == NULL && node2 == NULL){
		return false;
	} else{
		if(node1 == NULL || node2 == NULL)
			return false;
		else if(node1->data != node2->data)
			return false;
		else
			comparelinkedList(node1->next, node2->next);
	}
	return true;
}

void deletelinkedList(Node** node){
	Node* tmpNode;
	while(*node){
		tmpNode = *node;
		*node = tmpNode->next;
		delete tmpNode;
	}
	cout << "nothing in here!\n";
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
	Node* newHead;
	
	initNode(head, 20);
	display(head);
	addNode(head, 30);
	display(head);
	addNode(head, 40);
	display(head);
	addFront(&head, 5);
	display(head);
	addFront(&head, 10);
	display(head);
	Node* ptrDel = searchNode(head, 7);
	ptrDel = searchNode(head, 10);
	if(deleteNode(&head, ptrDel))
		cout << "deleted!\n";
	display(head);
	cout << "The list is copyed.\n";
	copylinkedList(head, &newHead);
	cout << "original : ";
	display(head);
	cout << "copyed : ";
	display(newHead);
	
	cout << "Comparing the two lists...\n";
	if(comparelinkedList(head, newHead))
		cout << "Yes, they are same!\n";
	else
		cout << "No, they are different!\n";
	cout << endl;

	cout << "Deleting the copied list\n";
	deletelinkedList(&newHead);
	display(newHead);
		
	return 0;
}
