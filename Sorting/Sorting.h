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

// BubbleSort
void BubbleSort(int arr[], int size){
	int tmp;
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size - 1 - i; j++){
			if(arr[j] > arr[j+1]){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}

// InsertionSort
void InsertionSort(int arr[], int size){
	int j, tmp;
	for(int i = 1; i < size; i++){
		j = i;
		while(j > 0 && arr[j-1]>arr[j]){
			tmp = arr[j];
			arr[j] = arr[j-1];
			arr[j-1] = tmp;
			j--;
		}
	}
}

// MergeSort
void Merge(int arr[], int size, int low, int middle, int high){
	int tmp[size];
	for(int i = low; i <= high; i++){
		tmp[i] = arr[i];
	}
	int i = low;
	int j = middle + 1;
	int k = low;

	while (i <= middle && j <= high){
		if(tmp[i] <= tmp[j]){
			arr[k] = tmp[i];
			++i;
		}
		else{
			arr[k] = tmp[j];
			++j;
		}
		++k;
	}
	while(i <= middle){
		arr[k] = tmp[i];
		++k;
		++i;
	}
}

void MergeSort(int arr[], int size, int low, int high){
	if(low < high){
		int middle = (low + high)/2;
		MergeSort(arr, size, low, middle);
		MergeSort(arr, size, middle+1, high);
		Merge(arr, size, low, middle, high);
	}
}




#endif
