#include <iostream>
#include <cstdlib>

#define MAX 100
using namespace std;

void QuickSort(int arr[], int lo, int hi){
    if(lo < hi){
        int i = lo, j = hi, x = arr[lo];
        while(i < j){
            while(i < j && arr[j] >= x)
                --j;
            if(i < j) 
                arr[i++] = arr[j];
            while(i < j && arr[i] < x)
                ++i;
            if(i < j)
                arr[j--] = arr[i];
        }
        arr[i] = x;
        QuickSort(arr, lo, i-1);
        QuickSort(arr, i+1, hi);
    }
}

int main(){
	int array[MAX];
	
	srand((unsigned int)time(NULL)); 
	for(int i=0; i<MAX; i++){
		array[i] = rand() % 1000;		
	}
	
	// print random data (unsorting...)	
	cout << "print unsorting data" << endl;
	for(int i=0; i<MAX; i++){
		cout << array[i] << "  ";
	}

	QuickSort(array, 0, MAX);
	
	cout << "\nprint sorting data" << endl;
	for(int i=0; i<MAX; i++){
		cout << array[i] << "  ";
	}
	cout << endl << "Sorting complete!!!\n";
	return 0;
}
