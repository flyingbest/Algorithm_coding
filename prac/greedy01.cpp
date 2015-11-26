#include <iostream>
using namespace std;

int coin[3] = {10, 7, 1};
int cnt[3];

int main(){
	int m, f = 0;

	cin >> m;
	for(int i = 0; i < 3; i++){
		if(coin[i] > m){
			i++;
		}
		else if(coin[i] < m){
			m -= coin[i];
			cnt[i]++;
		}
		else{
			f = 1;
			cnt[i]++;
			break;
		}
	}
	if(f != 1){
		cout << coin[0] << "원 동전은 " << cnt[0] << "개" << endl;
		cout << coin[1] << "원 동전은 " << cnt[1] << "개" << endl;
		cout << coin[2] << "원 동전은 " << cnt[2] << "개" << endl;
	}
	else
		cout << "해답을 구할 수 없습니다.\n";
	return 0;
}
