#include <iostream>
#include <algorithm>
#include <cstdlib>

#define MAX 100
using namespace std;

int main(int argc, char *argv[]){

	int arr[MAX];

	srand((unsigned int)time(NULL));
	for(int i = 0; i < MAX; i++){
		arr[i] = (rand() % 1000) + 1;
		cout << arr[i] << " ";
	}	

	sort(arr, arr+MAX);
	cout << endl << endl << "기본 algorithm에 있는 sort 함수 이용!" << endl << endl;
	
	for(int i = 0; i < MAX; i++){
		cout << arr[i] << " ";
	}

	return 0;
}

