#include <iostream>
using namespace std;

void print_array(int array[], int sta, int end){
	cout << endl << sta << "~" << end << " : ";
	for(int i = 0; i < sta; i++) cout << "   ";
	for(int i = sta; i <= end; i++) cout << array[i];
}

void Swap(int array[], int idx1, int idx2){
	int tmp;

	tmp = array[idx1];
	array[idx1] = array[idx2];
	array[idx2] = tmp;
} 

int partition(int array[], int sta, int end){
	int pivot, i, j, tmp;

	if(sta >= end) return 0;
	pivot = array[sta];
	i = sta;
	j = end + 1;

	while(1){
		do ++i; while (array[i] <= pivot && i <= end);
		do --j; while (array[j] > pivot);
		if(i >= j) break;
		Swap(array, i, j);
	}
	Swap(array, sta, j);
	return j;	
}

void QuickSort(int array[], int sta, int end){
	int pivot;

	if(sta >= end) return;
	pivot = partition(array, sta, end);
	print_array(array, sta, end);
	QuickSort(array, sta, pivot - 1);
	QuickSort(array, pivot + 1, end);
}

int main(int argc, char *argv[]){
	int array[] = {10, 3, 34, 5, 26, 4, 1, 6, 9, 19};
	int arraysize = sizeof(array) / sizeof(int);

	print_array(array, 0, arraysize - 1);
	QuickSort(array, 0, arraysize - 1);
	print_array(array, 0, arraysize - 1);
	
	return 0;
}

