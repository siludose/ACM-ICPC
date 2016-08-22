#include<iostream>
#include <string.h>
#include <stack>
using namespace std;
int a[1000];
int mid;
int min_mid;
int max_mid;
stack<int> s;

void input()
{
	int c;
	mid=500;
	s.push(mid);
	while(!s.empty())
	{
		
		cin>>c;
		if (c==-1)
		{
			s.pop();
		}
		else
		{
			mid=s.top();
			a[mid]+=c;
			s.pop();
			s.push(mid+1);
			s.push(mid-1);
		}
		if (min_mid>mid)
		{
			min_mid=mid;
		}
		if (max_mid<mid)
		{
			max_mid=mid;
		}
	}

}
int main()
{
	int n=1;
	while (n++)
	{
		min_mid=1000;
		max_mid=0;
		input();
		mid=500;
		if(a[mid]==0)
		{
			return 0;
		}
		int i=min_mid;
		if (a[mid]==0)
		{
			n--;
			continue;
		}
		else
		{
			cout<<"Case "<<n-1<<":"<<endl;
		}
		
		for (;i<max_mid;i++)
		{
			cout<<a[i]<<" ";
			a[i]=0;
		}
		cout<<a[max_mid];
		a[max_mid]=0;
		cout<<endl<<endl;
	}
	
	return 0;
}