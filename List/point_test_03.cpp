#include <iostream>
using namespace std;

struct superMan{
	int power;
	int age;
} KlarkKent; 

int main(){
		
	KlarkKent.power = 10;
	KlarkKent.age = 20;

	cout << KlarkKent.power << endl;
	cout << KlarkKent.age << endl;

	return 0;
}

