#include <iostream>
using namespace std;

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
} Node;

Node* createNode(int data){
	Node* newNode = new Node;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void insertNode(Node* tree, Node* newNode){
	if(newNode->data > tree->data){
		if(tree->right != NULL)
			insertNode(tree->right, newNode);
		else
			tree->right = newNode;
	}
	else if(newNode->data < tree->data){
		if(tree->left != NULL)
			insertNode(tree->left, newNode);
		else
			tree->left = newNode;
	}
}

Node* searchNode(Node* tree, int findData){
	if(tree == NULL) return NULL;
	if(tree->data == findData) return tree;
	else if(tree->data > findData)
		searchNode(tree->left, findData);
	else
		searchNode(tree->right, findData);
}

Node* findMinNode(Node* tree){
	if(tree == NULL) return NULL;
	if(tree->left != NULL) return findMinNode(tree->left);
	else return tree;
}

Node* removeNode(Node* tree, int delData){
	Node* tmpNode;
	
	if(tree == NULL) cout << "해당노드를 찾을 수 없음.\n";
	else if(tree->data >= delData) tree->left = removeNode(tree->left, delData);
	else if(tree->data < delData) tree->right = removeNode(tree->right, delData);
	else{
		if(tree->left != NULL && tree->right != NULL){
			tmpNode = findMinNode(tree->right);
			tree->data = tmpNode->data;
			tree->right = removeNode(tree->right, tmpNode->data);
		}
		else{
			tmpNode = tree;
			if(tree->left == NULL) tree = tree->right;
			else if(tree->right == NULL) tree = tree->left;
			delete tmpNode;
		}
	}
	return tree;
}

void printTree(Node* tree){
	if(tree == NULL) return;
	printTree(tree->left);
	cout << tree->data << " ";
	printTree(tree->right);
}

int main(){
	Node* root = NULL;
	root = createNode(20);
	//Node* root = createNode(20);
	
	insertNode(root, createNode(10));
	insertNode(root, createNode(5));
	insertNode(root, createNode(30));
	insertNode(root, createNode(25));
	insertNode(root, createNode(7));

	Node* findNode;
	int input;

	while(true){
		cin >> input;
		findNode = searchNode(root, input);
		
		if(findNode != NULL){
			cout << "해당 노드를 찾았습니다! 노드를 제거합니다.\n";
			removeNode(root, input);
			cout << "현재 트리 출력 : ";
			printTree(root); cout << endl;
		}
		else
			cout << "노드를 찾을 수 없습니다.\n";
	}
	return 0;
}

