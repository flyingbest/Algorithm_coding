#include <iostream>
#include <string.h>
using namespace std;

int scmp(const void *p1, const void *p2){
	char *v1, *v2;

	v1 = *(char **) p1;
	v2 = *(char **) p2;
	return strcmp(v1, v2);
}

int main(){
	cout << "문자열 비교" << endl;
	
	string text1; 
	string text2 = "ansxodbs";
	cin >> text1;

	while (text1 != "exit"){
		if(scmp(&text1, &text2) == 0){
			cout << "correct!" << endl;
		}
		else{
			cout << "not fit!" << endl;
		}
		cin >> text1;
	}
	return 0;
}

