#include <iostream>
using namespace std;

struct superMan{
	int power;
	int age;
}; 

int main(){
	struct superMan KlarkKent;
	
	KlarkKent.power = 10;
	KlarkKent.age = 20;

	cout << KlarkKent.power << endl;
	cout << KlarkKent.power << endl;

	return 0;
}

