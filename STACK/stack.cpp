#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#define DSS 20	//Default Stack Size

template <typename T>
class Stack{
public:
	Stack(int stack_size=DSS);
	~Stack();
	
	void Push(const T&) throw(...);
	T Pop() throw(...);
	const T& Top() const;
	
	int Size() const;

private:
	bool Empty() const;
	bool Full() const;

private:
	T* stack;
	const int stack_size;
	int top;
	int size;
};


