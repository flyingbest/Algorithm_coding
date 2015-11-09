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
			cout << "Found node < " << n << " > !!!\n";
			return cur;
		}
		cur = cur->next;
	}
	cout << "No node < " << n << " > in this list.\n";
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

Node* reverse(Node** head){
	Node *parent = *head;
	Node *me = parent->next;
	Node *child = me->next;

	parent->next = NULL;
	while(child){
		me->next = parent;
		parent = me;
		me = child;
		child = child->next;
	}
	me->next = parent;
	*head = me;
	return *head;
}

void copylinkedList(Node* node, Node** copynode){
	if(node != NULL){
		*copynode = new Node;
		(*copynode)->data = node->data;
		(*copynode)->next = NULL;
		copylinkedList(node->next, &((*copynode)->next));
	}
}

bool comparelinkedList(Node* node1, Node* node2){
	if(node1 == NULL && node2 == NULL){
		return true;
	}else{
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
}

void deletelinkedList(Node** node){
	Node* tmpNode;
	while(*node){
		tmpNode = *node;
		*node = tmpNode->next;
		delete tmpNode;
	}
}

int main(){
	Node* head = new Node;

	initNode(head, 20);
	printlist(head);
	addNode(head, 30);
	printlist(head);
	addFront(&head, 10);
	printlist(head);
	addNode(head, 40);
	printlist(head);
	addNode(head, 50);
	printlist(head);
	cout << "Node is complete!===============\n";
	
	cout << "\nIs num 7 exist in this list???\n";
	int num = 7;
	Node* ptrNum = searchNode(head, num);
	cout << "================================\n\n";
	printlist(head);
	
	cout << "Let's delete node 10!\n";
	ptrNum = searchNode(head, 10);
	if(deleteNode(&head, ptrNum))
		cout << "delete	complete!===============\n";
	else
		cout << "delete Failed!=================\n";
	printlist(head);

	cout << "\nLet's delete node 15!\n";
	ptrNum = searchNode(head, 15);
	if(deleteNode(&head, ptrNum))
		cout << "delete	complete!===============\n";
	else
		cout << "delete Failed!=================\n";
	printlist(head);
	cout << endl;

	
	Node* newHead;
	cout << "Let's copy nodelist!=============\n";
	copylinkedList(head, &newHead);
	cout << "original nodelist : ";
	printlist(head);
	cout << "copyed nodelist : ";
	printlist(newHead);
	cout << "================================\n\n";

	cout << "Comparing the two lists!\n";
	if(comparelinkedList(head, newHead))
		cout << "Same!!!\n";
	else
		cout << "Different!!!\n";
	cout << "================================\n\n";
	
	cout << "Deleting the copied list!\n";
	deletelinkedList(&newHead);
	cout << "original nodelist : ";
	printlist(head);
	cout << "copyed nodelist : ";
	printlist(newHead);		

	return 0;
}
