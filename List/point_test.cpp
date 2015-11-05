#include <iostream>
using namespace std;

int main(){
	int *p;

	int i = 10;
	
	p = &i;

	cout << "Address of i : (p) : " << p << endl;
	cout << "Value of i : (*p) : " << *p << endl;
	cout << endl;

	*p = 20;

	cout << "Address of i : (p) : " << p << endl;
	cout << "Value of i : (*p) : " << *p << endl;

	cout << endl;
	int *p2 = p; //copy of p(copies address in p).
	int **r = &p;	//reference to p(assigns address of p).

	cout << "copy of p : (p2) : " << p2 << endl;
	cout << "copy of p : (*p2) : " << *p2 << endl;
	cout << endl;
	cout << "Address of p : (r) : " << r << endl;
	cout << "Address of i : (*r) : " << *r << endl;
	cout << "Value of i : (**r) : " << **r << endl;

	cout << "========================================\n\n";

	int ar[]={1,2,3,4,5};
	int *pi;

	pi = ar;
	cout << "첫번째 요소 : " << *pi << endl;
	pi+(i*sizeof(int));
	cout << "두번째 요소 : " << *pi << endl;

	return 0;
}

