#include <iostream>
#include <cstdlib>

#define MAX 10000
using namespace std;

int main(){
	int array[MAX];
	
	srand((unsigned int)time(NULL)); 
	for(int i=0; i<MAX; i++){
		array[i] = rand() % 1000000;		
	}
	
	// print random data (unsorting...)	
	for(int i=0; i<MAX; i++){
		cout << array[i] << " ";
	}
	return 0;
}

