#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void display(int arr[], int size){
	for(int i=0; i<size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

void selectionSort(int arr[], int size){
	int first, tmp;
	for(int i=size-1; i>0; i--){
		first = 0;
		for(int j = 1; j <= i; j++){
			if(arr[j] > arr[first]){
				first = j;
			}
			tmp = arr[first];
			arr[first] = arr[i];
			arr[i] = tmp;
		}
	}
}

int main(){
	const int size = 10;
	int numbers[size];
	srand(unsigned(time(NULL)));
	for(int i = 0; i < size; i++){
		numbers[i] = (rand() % 100) + 1;
		cout << numbers[i] << " ";
	}
	cout << endl;
	selectionSort(numbers, size);
	display(numbers, size);
	return 0;
}

