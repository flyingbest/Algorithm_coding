#include <iostream>
#include <string>
using namespace std;

typedef struct node{
	int id;
	string name;
	struct node* next;
} Node;

void display(Node* head){
	Node* cur = head;
	while(cur){
		cout << "id : " << cur->id << ", name : " << cur->name << endl;
		cur = cur->next;
	}
}

void initNode(Node* head, int _id, string _name){
	head->id = _id;
	head->name = _name;
	head->next = NULL;
}

void addNode(Node* head, int _id, string _name){
	Node* newNode = new Node;
	newNode->id = _id;
	newNode->name = _name;
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

void addFront(Node** head, int _id, string _name){
	Node* newNode = new Node;
	newNode->id = _id;
	newNode->name = _name;
	newNode->next = *head;
	*head = newNode;
}

Node* searchNode_id(Node* head, int _id){
	Node* cur = head;
	while(cur){
		if(cur->id == _id){
			cout << "Found this ( " << _id << " ) id in this list." << endl;
			return cur;
		}
		cur = cur->next;
	}
	cout << "CAN'T Find this ( " << _id << " ) id in this list." << endl;
}

Node* searchNode_name(Node* head, string _name){
	Node* cur = head;
	while(cur){
		if(cur->name == _name){
			cout << "Found this ( " << _name << " ) name in this list." << endl;
			return cur;
		}
		cur = cur->next;
	}
	cout << "CAN'T Find this ( " << _name << " ) name is this list." << endl;
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

int main(){
	Node* head = new Node;
	
	initNode(head, 10, "ansxodbs");	addNode(head, 20, "gil-dong");
	addFront(&head, 1, "rlawltn"); addNode(head, 30, "iron-man");
	addNode(head, 40, "jarvis"); addNode(head, 50, "ultron");
	cout << "linked list >> " << endl;
	display(head);

	cout << "=========================================================\n";
	
	Node* ptrDel = searchNode_id(head, 10);
	ptrDel = searchNode_name(head, "ansxodbs");
	ptrDel = searchNode_id(head, 15);
	ptrDel = searchNode_name(head, "nobody");

	cout << "linked list >> " << endl;
	display(head);

	cout << "=========================================================\n";

	int id;
	cout << "Enter the id that you deleted : ";
	cin >> id;
	
	ptrDel = searchNode_id(head, id);
	if(deleteNode(&head, ptrDel))
		cout << "delete completed!" << endl;
	else
		cout << "delete failed!" << endl;

	string name;
	cout << "Enter the name that you deleted : ";
	cin >> name;
	
	ptrDel = searchNode_name(head, name);
	if(deleteNode(&head, ptrDel))
		cout << "delete completed!" << endl;
	else
		cout << "delete failed!" << endl;
	
	cout << "=========================================================\n";
	cout << "linked list >> " << endl;
	display(head);

	return 0;
}
