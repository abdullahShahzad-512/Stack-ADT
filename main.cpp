//#include <iostream>
#include "Stack.h"
//using namespace std;
int main()
{
	Stack <int> s;
	Stack <int>s2;
	s.push(70);
	s2.push(20);
	s2.pop();
	s = s2;
	/*for (int i = 0; i <=12; i++)
	{
		s.push(i);
	}*/
	s2.push(901);
	s2.push(902);
	s2.push(903);
	while (!(s.isEmpty()))
	{
		cout << endl << s.pop();
	}
	while (!(s2.isEmpty()))
	{
		cout << endl << s2.pop();
	}
	return 0;
}