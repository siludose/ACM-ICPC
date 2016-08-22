#include<iostream>
#include<stack>
using namespace std;
stack<int> stack1;
stack<int> stack2;
int m;
int temp;
int queue_push(int i)
{
	if(stack2.empty())
	{
		stack1.push(i);
	}
	else
	{
		while (!stack2.empty())
		{
			temp=stack2.top();
			stack2.pop();
			stack1.push(temp);
		}
	}
}
int queue_pop( )
{
	while(!stack1.empty())
	{
		temp=stack1.top();
		stack1.pop();
		stack2.push(temp);
	}
	stack2.pop();
}
int main()
{
	while(1)
	{
		cin>>m;
	}
	return 0;
}