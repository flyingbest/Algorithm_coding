#include <iostream>
using namespace std;

typedef struct node{
	int key_value;
	struct node* p_left;
	struct node* p_right;
} Node;

/*
Node* insert(Node* p_tree, int key);
Node* search(Node* p_tree, int key);
Node* remove(Node* p_tree, int key);
void destroyTree(Node* p_tree);
*/

void printTree(Node* p_tree){
	//cout << "check_point_2" << endl;
	if(p_tree != NULL){
		//cout << "check_point_3" << endl;
		printTree(p_tree->p_left);
		cout << p_tree->key_value << " ";
		printTree(p_tree->p_right);	
	}
}

Node* insertNode(Node* p_tree, int key){
	// 탈출 조건 - 빈 트리를 만나거나 새로운 노드 값을 삽입해야 할 때
	if(p_tree == NULL){
		Node* p_new_tree = new Node;
		p_new_tree->p_left = NULL;
		p_new_tree->p_right = NULL;
		p_new_tree->key_value = key;
		//cout << "check_point_1" << endl;
		return p_new_tree;
	}

	// 값을 삽입할 곳이 왼쪽 서브트리인지 오른쪽 서브트리인지
	// 해당 노드의 값에 따라 결정.
	if(key < p_tree->key_value){
		// p_tree->left에 따라 키를 추가하여 새로운 트리를 빌드.
		// 그리고 기존 p_tree->left를 새로운 트리 포인터로 교체.
		// p_tree->left가 NULL이면 p_tree->p_left 포인터를 설정.
		// (NULL이 아니면 p_tree->p_left는 변경되지 않지만,
		// 설정한다고 해서 잘못될 것은 없다.
		p_tree->p_left = insertNode(p_tree->p_left, key);
	}
	else{
		// 오른쪽에 삽입하는 것은 왼쪽일 때와 완벽하게 대칭이다.
		p_tree->p_right = insertNode(p_tree->p_right, key);
	}
	return p_tree;
}

Node* searchNode(Node* p_tree, int key){
	// 빈 트리
	if(p_tree == NULL){
		return NULL;
	}
	// 키를 찾으면 임무 완수
	else if(key == p_tree->key_value){
		cout << "Found!" << endl;
		return p_tree;
	}
	// 찾지 못했으면, 왼쪽 서브트리 또는 오른쪽 서브트리에서 확인
	else if(key < p_tree->key_value){
		return searchNode(p_tree->p_left, key);
	}
	else{
		return searchNode(p_tree->p_right, key);
	}
}

void destroyTree(Node* p_tree){
	if(p_tree != NULL){
		destroyTree(p_tree->p_left);
		destroyTree(p_tree->p_right);
		cout << "Deleting node: " << p_tree->key_value << endl;
		delete p_tree;
	}
}

int main(){
	Node* tree;

	tree = insertNode(NULL, 20);
	tree = insertNode(tree, 30);
	tree = insertNode(tree, 10);
	tree = insertNode(tree, 40);
	tree = insertNode(tree, 1);

	printTree(tree);
	
	searchNode(tree, 40);

	destroyTree(tree);
	
	return 0;
}

