#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	
	// 2. 시드값 설정.
	//srand(10);
	// 3. 시드값에 time 추가.
	srand((unsigned int)time(NULL)); 
	for(int i=0; i<10; i++){
		// 1. 현재 지점에 rand()만 생성할 경우 매번 같은 수가 나온다.
		cout << rand() % 10000 + 1 << endl;		
	}

	return 0;
}

//rand 함수는 시드(seed)라는 값에 의해 생성되므로 시드값을 설정해주지 않아 같은 시드값으로 실행된다.
//이를 해결하기 위해 srand 함수를 이용해 시드값을 설정해주면 된다.
//하지만 같은 시드값으로 재실행을 하면 같은 결과가 나온다.
//실행할 때마다 시드값을 직접 지정할 수 없으므로 보통 srand 인자에 ctime 라이브러리의 time 함수를 추가해주면 된다.
//난수들을 보면 결과값이 0 ~ RAND_MAX 사이의 값이 나오므로 매우 큰 수들이 나온다.
//이 값들을 원하는 범위 내에서 나오게 하기 위해서는 나머지 연산을(%)을 이용하면 된다.

//rand() % M을 하면 0 ~ (M-1)까지의 수가 생성
//rand() % M + N을 하면 N ~ (M+N-1)까지의 수가 생성
//rand() % 100이면 0~99까지의 수가  ( 0 ~ (100-1) )
//rand() % 100 + 1이면 1~100까지의 수가  ( 1 ~ (100+1-1) )
