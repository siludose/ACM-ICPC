#include<iostream>
using namespace std;
int array[50];
int array_next[50]={0};

void print(int n)
{
	for (int i=0;array_next[i]=-1;i=array_next[i])
	{
		cout<<array[i]<<"           ";
	}
}
void array_delete(int n,int deletenum)
{
	int i=0;
	while(array[i]!=deletenum)
	{
		i=array_next[i];
	}
	array_next[i-1]=array_next[i];
}
void array_add(int n,int numadd)
{
	int temp;
	for (int i=n;i<n+numadd;i++)
	{
		cin>>temp;
		array[i++]=temp;
		array_next[i-1]=i;
	}
}
int main() 
{
	int temp;
	int n;
	int i=0;
	
	while (n--)
	{

		cin>>temp;
		array[i++]=temp;
		array_next[i-1]=i;
	}
	
	return 0;
}