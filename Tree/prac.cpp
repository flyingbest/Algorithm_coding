#include <iostream>
using namespace std;

typedef struct node{
	int data;
	struct node* left;
	struct node* right;
}	bstnode;

void printInorder(bstnode* root){
	if(root != NULL){
		printInorder(root->left);
		cout << root->data << " ";
		printInorder(root->right);
	}
}

bstnode* GetNewNode(int data){
	bstnode* newNode = new bstnode;
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

bstnode* insertNode(bstnode* root, int data){
	if(root == NULL){
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

bool searchNode(bstnode* root, int data){
	if(root == NULL) return false;
	else if(root->data == data) return true;
	else if(data <= root->data) return searchNode(root->left, data);
	else return searchNode(root->right, data);
}

int main(){
	bstnode* root = NULL;
	root = insertNode(root, 10);
	root = insertNode(root, 20);
	root = insertNode(root, 30);
	
	printInorder(root);
	
	return 0;
}
	
	
