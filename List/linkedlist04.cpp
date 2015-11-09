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
			cout << "Node < " << n << " > exist in this list.\n";
			return cur;
		}
		cur = cur->next;
	}
	cout << "Node < " << n << " > NOT exist in this list.\n";
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

void copylinkedList(Node* node, Node** cpnode){
	if(node != NULL){
		*cpnode = new Node;
		(*cpnode)->data = node->data;
		(*cpnode)->next = NULL;
		copylinkedList(node->next, &((*cpnode)->next));
	}
}

// same : return true;	differnt : return false;
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

	cout << "\n=====================================\n";
	Node* newHead;
	copylinkedList(head, &newHead);
	cout << "original node : ";
	printlist(head);
	cout << "copy node : ";
	printlist(newHead);
	cout << "\n=====================================\n";

	if(comparelinkedList(head, newHead))
		cout << "Match!!!\n";
	else
		cout << "Different!!!\n";
	cout << "\n=====================================\n";

	int num = 10;
	Node* ptrDel = searchNode(head, num);
	
	if(deleteNode(&head, ptrDel))
		cout << "delete complete!\n";
	else
		cout << "delete failed!\n";
	printlist(head);
	cout << endl;
	cout << "\n=====================================\n";
	
	ptrDel = searchNode(head, 25);
	if(deleteNode(&head, ptrDel))
		cout << "delete complete!\n";
	else
		cout << "delete failed!\n";
	printlist(head);
	cout << endl;
	cout << "\n=====================================\n";

	if(comparelinkedList(head, newHead))
		cout << "Match!!!\n";
	else
		cout << "Different!!!\n";
	cout << "\n=====================================\n";

	cout << "original node : ";
	printlist(head);
	cout << "copy node : ";
	printlist(newHead);
	cout << "\n=====================================\n";

	deletelinkedList(&newHead);	
	cout << "copy node : ";
	printlist(newHead);

	return 0;
}
