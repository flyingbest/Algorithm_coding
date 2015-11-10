// linked list example - using struct

#include <iostream>
#include <cstring>
using namespace std;

struct node* initNode(char*, int);
void displayNode(struct node*);
void displaylist(struct node*);
void addNode(struct node*);
struct node* searchName(struct node*, char*);
void deleteNode(struct node*);
void insertNode(struct node*);
void deletelist(struct node*);

typedef struct node{
	char name[20];
	int id;
	struct node* next;
} Node;

Node* head = (Node*) NULL;
Node* tail = (Node*) NULL;

// allocates memory for the node
// assign values to the member of the structure
Node* initNode(char* name, int id){
	Node* ptr = new Node;
	
	// error? then just return
	if(ptr == NULL){
		return static_cast<Node*>(NULL);
			// assign it
			// then return pointer to ne node
	else{
		strcpy(ptr->name, name);
		ptr->id = id;
		return ptr;
	}
}

// adding to the end of list
void addNode(Node* newNode){
	// if there is no node, put it to head
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}

	// link in the new_node to the tail of the list
	// then mark the next field as the end of the list
	// adjust tail to point to the last node

	tail->next = newNode;
	newNode->next = NULL;
	tail = newNode;
}

void insertNode(Node* newNode){
	Node* tmp;
	Node* prev;
	
	if(head == NULL){		// if an empty list,
		head = newNode;		// set 'head to it
		tail = newNode;
		head->next = NULL;	// set end of list to NULL
		return;
	}
	
	tmp = head;			// start at beginning of list
									// while currentname < newname
	while(strcmp(tmp->name, newNode->name) < 0){
									// to be inserted then
		tmp = tmp->next;	// goto the next node in list
		if(tmp == NULL)		// don't go past end of list
			break;
	}

	if(
		


