#include <iostream>

int factorial(int n){
	if(n == 0){
		return 1;
	}
	else{
		return n * factorial(n-1);
	}
}

int main(){
	int result = factorial(3);
	std::cout << "result : " << result << std::endl;

	return 0;
}
