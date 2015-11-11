#include <iostream>
using namespace std;

int main(){
	int votes[10];

	for(int i = 0; i < 10; i++){
		votes[i] = 0;
	}

	int candidate;
	cout << "Vote fo the candidate of your choice, using numbers: " << endl;
	cin >> candidate;

	while(0 <= candidate && candidate <= 9){
		votes[candidate]++;
		cout << "Please enter another vote : ";
		cin >> candidate;
	}
	for(int i = 0; i < 10; i++){
		cout << votes[i] << endl;
	}
	
	return 0;
}

