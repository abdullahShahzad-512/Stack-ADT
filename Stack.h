#include <iostream>
using namespace std;
#ifndef STACK_H
#define STACK_H

template <typename T>
class Stack
{
	T* data;
	int capacity;
	int top;
	void reSize(int);
public:
	Stack();
	Stack(const Stack <T>&);
	Stack& operator = (const Stack <T>&);
	~Stack();

	void push(T val);
	T pop();
	T stackTop();
	bool isFull();
	bool isEmpty();
	int getCapacity();
	int getNumberOfElements();
};







template <typename T>
Stack<T>& Stack<T> :: operator = (const Stack <T>& ref)
{
	if (this == &ref)
	{
		return *this;
	}
	this -> ~Stack();
	if (ref.data == nullptr)
	{
		return *this;
	}
	capacity = ref.capacity;
	top = ref.top;
	data = new T[capacity];
	for (int i = 0; i < top; i++)
	{
		data[i] = ref.data[i];
	}
	return *this;
}
template <typename T>
void Stack<T>::reSize(int newSize)
{
	T* temp = new T[newSize];
	int i = 0;
	for (i; i < top; i++)
	{
		temp[i] = data[i];
	}
	this->~Stack();
	data = temp;
	capacity = newSize;
	top = i;
}
template <typename T>
Stack <T>::Stack()
{
	data = nullptr;
	capacity = 0;
	top = 0;
}
template <typename T>
Stack<T> ::Stack(const Stack <T>& ref)
{
	if (this == &ref)
	{
		return *this;
	}
	this -> ~Stack();
	capacity = ref.capacity;
	top = ref.top;
	data = new T[capacity];
	for (int i = 0; i < top; i++)
	{
		data[i] = ref.data[i];
	}
	return *this;
}

template <typename T>
Stack<T>::~Stack()
{
	if (!data)
		return;
	delete[]data;
	data = nullptr;
	capacity = 0;
	top = 0;
}
template <typename T>
void Stack <T>::push(T val)
{
	if (isFull())
		reSize(capacity == 0 ? 1 : capacity * 2);
	data[top++] = val;
}
template <typename T>
T Stack <T>::pop()
{
	if (isEmpty())
		exit(0);

	T val = data[--top];
	if (top > 0 && top == capacity / 4)
		reSize((capacity / 2));

	return val;
}
template <typename T>
T Stack <T>::stackTop()
{
	if (isEmpty())
		exit(0);
	return data[top - 1];
}
template <typename T>
bool Stack <T>::isFull()
{
	if (top == capacity)
		return true;
	return false;
}
template <typename T>
bool Stack <T>::isEmpty()
{
	if (top == 0)
		return true;
	return false;
}
template <typename T>
int Stack <T>::getCapacity()
{
	return capacity;
}
template <typename T>
int Stack <T>::getNumberOfElements()
{
	return top;
}
#endif // !STACK_H
