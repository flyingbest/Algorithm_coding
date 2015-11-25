#include <iostream>
using namespace std;

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
} BstNode;

BstNode* GetNewNode(int data){
	BstNode* newNode = new BstNode;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	// simplely like this
	// newNode->left = newNode->right = NULL;
	return newNode;
}

BstNode* insertNode(BstNode* root, int data){
	if(root == NULL){	// empty tree
		root = GetNewNode(data);
		return root;
	}
	else if(data <= root->data){
		root->left = insertNode(root->left, data);
	}
	else{
		root->right = insertNode(root->right, data);
	}
	return root;
}

bool searchNode(BstNode* root, int data){
	if(root == NULL) return false;
	else if(root->data == data) return true;
	else if(data <= root->data) return searchNode(root->left, data);
	else return searchNode(root->right, data);
}

int main(){
	BstNode* root = NULL;	// creating an empty tree
	root = insertNode(root, 15);	root = insertNode(root, 10);
	root = insertNode(root, 20);	root = insertNode(root, 25);
	root = insertNode(root, 5); 	root = insertNode(root, 12);

	int num;
	while(true){
		cout << "Enter number be searched\n";
		cin >> num;
		
		if(searchNode(root, num) == true) cout << "Found!\n";
		else cout << "Not Found!\n";
	}
	return 0;
}

