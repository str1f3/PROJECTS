
#include<iostream>
using namespace std;
#include"Stack.h"
#include<string>
#include<iomanip>
​
template<class Type>
void postfix(Stack<Type> s)
{
	string e;
	float num, num1, num2;
	cin >> e;
	while (e != "=") 
	{
		if (e == "+")
		{
			num1 = s.top();
			s.pop();
			num2 = s.top();
			s.pop();
			s.push(num1 + num2);
		}
		else if(e == "-")
		{
			num1 = s.top();
			s.pop();
			num2 = s.top();
			s.pop();
			s.push(num2 - num1);
		}
		else if (e == "*")
		{	
			num1 = s.top();
			s.pop();
			num2 = s.top();
			s.pop();
			s.push(num1* num2);
		}
		else if (e == "/")
		{	
			num1 = s.top();
			s.pop();
			num2 = s.top();
			s.pop();
			s.push(num2 / num1);
		}
		else
		{
			num = stof(e);
			s.push(num);
		}
		cin >> e;
	}
	cout << setprecision(2) << fixed << s.top() << endl;
}
​
int main()
{
	/*Stack<int> s(10);
	cout<<"Is empty stack? "<<s.isEmptyStack() << endl;
	s.push(10); s.push(2); s.push(25);
	cout << "Top = "<<s.top() << endl;
	s.printStack();
	s.pop();
	cout << "Top = " << s.top() << endl;
	s.printStack();
	cout << "Is full stack? " << s.isFullStack() << endl;*/
​
	//code for postfix evaluation
	Stack<float> s(10);
	postfix(s);
	return 0;
}
