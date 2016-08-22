#include<iostream>
using namespace std;
int abc(int a[])
{
	a[0]=4;
}
int main()
{
	int a[2]={1,2};
	abc(a);
	cout<<a[0];
}
