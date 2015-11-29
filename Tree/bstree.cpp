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

int findMin(BstNode* root){
	if(root == NULL){
		cout << "Error : Tree is empty\n";
		return -1;
	}
	/*
	BstNode* cur = root;
	while(cur->left != NULL){
		cur = cur->left;
	}
	return cur->data;
	*/
	// second method.
	if(root->left == NULL){
		return root->data;
	}
	// search in left subtree.
	return findMin(root->left);
}

int findMax(BstNode* root){
	if(root == NULL){
		cout << "Error : Tree is empty\n";
		return -1;
	}
	else if(root->right == NULL){
		return root->data;
	}
	return findMax(root->right);
}

BstNode* deleteNode(BstNode* root, int del){
	if(root == NULL){
		return root;
	}
	else if(del < root->data){
		root->left = deleteNode(root->left, del);
	}
	else if(del > root->data){
		root->right = deleteNode(root->right, del);
	}
	else{
		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
		}
		else if(root->left == NULL){
			BstNode* tmp = root;
			root = root->right;
			delete tmp;
		}
		else if(root->right == NULL){
			BstNode* tmp = root;
			root = root->left;
			delete tmp;
		}
		else{
			int Delnum = findMin(root->right);
			root->data = Delnum;
			root->right = deleteNode(root->right, Delnum);
		}
	//return root;	// 위치 수정!!!
	}
	return root;
}		

/*
BstNode* deleteNode(BstNode* root, int deldata){
	if(root == NULL){return root;}
	else if(deldata < root->data){root->left = deleteNode(root-left, deldata);}
	else if(deldata > root->data){root->right = deleteNode(root->right, deldata);}
	else{
		//case 1 : No child
		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;
		}
		//case 2 : One child
		else if(root->left == NULL){
			BstNode* tmp = root;
			root = root->right;
			delete tmp;
		}
		else if(root->right == NULL){
			BstNode* tmp = root;
			root = root->left;
			delete tmp;
		}
		//case 3 : 2 children
		else{
			BstNode* tmp;
			tmp->data = findMin(root->right);
			root->data = tmp->data;
			root->right = deleteNode(root->right, tmp ->data);
		}
	}	
	return root;
}
*/

void printInorder(BstNode* root){
	if(root != NULL){
		printInorder(root->left);
		cout << root->data << " ";
		printInorder(root->right);
	}
}

void printPreorder(BstNode* root){
	if(root != NULL){
		cout << root->data << " ";
		printPreorder(root->left);
		printPreorder(root->right);
	}
}

void printPostorder(BstNode* root){
	if(root != NULL){
		printPostorder(root->left);
		printPostorder(root->right);
		cout << root->data << " ";
	}
}

int main(){
	cout << "Program START >>" << endl;
	cout << "===============================================================" << endl;
	
	cout << "creating tree >>   ";
	BstNode* root = NULL;	// creating an empty tree
	root = insertNode(root, 20);	root = insertNode(root, 30);
	root = insertNode(root, 25);	root = insertNode(root, 10);
	root = insertNode(root, 15); 	root = insertNode(root, 5);	root = insertNode(root, 35);
	printInorder(root); cout << endl;
	
	cout << "===============================================================" << endl;
	int searchnum;
	cout << "Enter number be searched(any num) : ";
	cin >> searchnum;
	if(searchNode(root, searchnum) == true) cout << "Found! The searchnum " << searchnum << " is exist\n";
	else cout << "Not Found! The searchnum " << searchnum << " is NOT exist\n";

	cout << "===============================================================" << endl;
	int min;
	cout << "let's find Min!\n";
	min = findMin(root);
	cout << "min : " << min << endl;
	cout << "tree >>   ";
	printInorder(root); cout << endl;
	
	cout << "===============================================================" << endl;
	int max;
	cout << "let's find Max!\n";
	max = findMax(root);
	cout << "max : " << max << endl;
	cout << "tree >>   ";
	printInorder(root); cout << endl;

	cout << "===============================================================" << endl;
	int delnum;
	cout << "Enter the delete Num(20) : ";
	cin >> delnum;
	/*
	BstNode* tmp = deleteNode(root, delnum);
	printInorder(tmp); cout << endl;
	*/
	root = deleteNode(root, delnum);
	printInorder(root); cout << endl;
	
	cout << "===============================================================" << endl;
	cout << "Printing Test" << endl;
	cout << "PreOrder(25, 10, 5, 15, 30, 35) >>   ";
	printPreorder(root); cout << endl;	
	cout << "PostOrder(5, 15, 10, 35, 30, 25) >>   ";
	printPostorder(root); cout << endl;

	return 0;
}

