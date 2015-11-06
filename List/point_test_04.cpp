#include <iostream>
using namespace std;

typedef struct superMan super;

struct superMan{
	int power;
	int age;
}; 

int main(){
	super KlarkKent;

	KlarkKent.power = 10;
	KlarkKent.age = 20;

	cout << KlarkKent.power << endl;
	cout << KlarkKent.age << endl;

	return 0;
}

