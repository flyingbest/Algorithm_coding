#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Sorting.h"

#define MAX 100
using namespace std;

void printData(int arr[], int arr_size){
	for(int i = 0; i < arr_size; i++)
		cout << arr[i] << " ";
	cout << "\n\n====================================================\n\n";
}

int main(int argc, char *argv[]){

	// making unsorting data set.
	int arrA[MAX];
	ofstream outFile("inputdata.txt");

	srand((unsigned int)time(NULL));
	for(int i = 0; i < MAX; i++){
		arrA[i] = (rand() % 1000) + 1;
		outFile << arrA[i] << " ";
	}
	outFile.close();

	// IO redirection from file
	ifstream in("inputdata.txt");
	streambuf *cinbuf = cin.rdbuf();
	cin.rdbuf(in.rdbuf());

	ofstream out("outputdata.txt");
	streambuf *coutbuf = cout.rdbuf();
	cout.rdbuf(out.rdbuf());

	int inputArr[MAX];
	for(int i = 0; i < MAX; i++)
		cin >> inputArr[i];

	int copyArr[MAX];
	clock_t t1, t2;
	double Stime_arr[10] = {0,};

	// Quick Sort
	for(int i = 0; i < MAX; i++)	// making copyArr.
		copyArr[i] = inputArr[i];
	t1 = clock();
	QuickSort(copyArr, 0, MAX - 1);
	t2 = clock();	
	Stime_arr[0] = (double)(t2-t1)/CLOCKS_PER_SEC;	
	cout << "Quick Sort" << " - time : " << Stime_arr[0] << endl << endl;
	printData(copyArr, MAX);

	// Selection Sort
	for(int i = 0; i < MAX; i++)	// making copyArr.
		copyArr[i] = inputArr[i];
	t1 = clock();
	SelectionSort(copyArr, MAX);
	t2 = clock();	
	Stime_arr[1] = (double)(t2-t1)/CLOCKS_PER_SEC;
	cout << "Selection Sort" << " - time : " << Stime_arr[1] << endl << endl;
	printData(copyArr, MAX);
				
	// Bubble Sort
	for(int i = 0; i < MAX; i++)	// making copyArr.
		copyArr[i] = inputArr[i];
	t1 = clock();
	BubbleSort(copyArr, MAX);
	t2 = clock();	
	Stime_arr[2] = (double)(t2-t1)/CLOCKS_PER_SEC;
	cout << "Bubble Sort" << " - time : " << Stime_arr[2] << endl << endl;
	printData(copyArr, MAX);
	
	// Insertion Sort
	for(int i = 0; i < MAX; i++)	// making copyArr.
		copyArr[i] = inputArr[i];
	t1 = clock();
	InsertionSort(copyArr, MAX);
	t2 = clock();	
	Stime_arr[3] = (double)(t2-t1)/CLOCKS_PER_SEC;
	cout << "Insertion Sort" << " - time : " << Stime_arr[3] << endl << endl;
	printData(copyArr, MAX);
	
	// Merge Sort
	for(int i = 0; i < MAX; i++)	// making copyArr.
		copyArr[i] = inputArr[i];
	t1 = clock();
	MergeSort(copyArr, MAX, 0, MAX-1);
	t2 = clock();	
	Stime_arr[4] = (double)(t2-t1)/CLOCKS_PER_SEC;
	cout << "Merge Sort" << " - time : " << Stime_arr[4] << endl << endl;
	printData(copyArr, MAX);
	
	// Heap sort
	

	cout << endl;

	// reset IO
	cin.rdbuf(cinbuf);
	cout.rdbuf(coutbuf);

	return 0;
}

