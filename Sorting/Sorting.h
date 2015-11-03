#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#ifndef SORTING_H
#define SORTING_H

// declaration for sort functions

// QuickSort
void QuickSort(int arr[], int left, int right){
	int i = left;
	int j = right;
	int tmp;
	int pivot = arr[(left+right)/2];

	while(i<=j){
		while(arr[i] < pivot)
			i++;
		while(arr[j] > pivot)
			j--;
		if(i<=j){
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}
	if(left < j)
		QuickSort(arr, left, j);
	if(i < right)
		QuickSort(arr, i, right);
}


// SelectionSort
void SelectionSort(int arr[], int size){
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


#endif
