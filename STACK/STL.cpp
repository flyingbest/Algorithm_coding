#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

int main(){
	cout << "STACK=============================\n";

	stack<string> st;
	
	st.push("what");
	st.push("is");
	st.push("your");
	st.push("favorite");
	st.push("color?");

	int cnt = st.size();
	for(int i = 0; i < cnt; i++){
		cout << st.top() << endl;
		st.pop();
	}
	
	if(st.empty())
		cout << "Empty!!!" << endl;
	else
		cout << "NOT empty!!!" << endl;

	cout << "\n\nQUEUE=================================\n";

	queue<float> qu;

	qu.push(0.3);
	qu.push(0.5);
	qu.push(0.7);
	qu.push(0.9);
	qu.push(1.1);

	cnt = qu.size();
	for(int i = 0; i < cnt; i++){
		cout << "Front : " << qu.front() << "  Back : " << qu.back() << endl;
		qu.pop();
	}

	if(qu.empty())
		cout << "Empty!!!" << endl;
	else
		cout << "NOT empty!!!" << endl;
		

	return 0;
}

