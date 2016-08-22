#include<iostream>
using namespace std;
const int inf=10000000000;
__int64 t;
void count(int *s,int l,int m,int r)
{
	int lenl=m-l+1;
	int lenr=r-m;
	int *left=new int[lenl+2];
	int *right=new int[lenr+2];
	
	int i=0,j=0;
	for(;i<lenl;i++)
	{
		left[i]=s[l+i];
	}
	left[lenl]=inf;
	for(;j<lenr;j++)
	{
		right[j]=s[m+j+1];
	}
	right[lenr]=inf;
	
	i=j=0;
	for(int k=l;k<=r;k++)
	{
		if(left[i]<=right[j])
		{
			s[k]=left[i++];
		}
		else
		{
			s[k]=right[j++];
			t+=lenl-i;
		}
	}
	delete left;
	delete right;
	return;
}
void mergesort(int *s,int l,int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		mergesort(s,l,m);
		mergesort(s,m+1,r);
		count(s,l,m,r);
	}
	return ;
}
int main()
{
	int n;
	while(cin>>n)
	{
		if(!n)
			break;
		int *s=new int[n+1];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&s[i]);
		}
		
		t=0;
		mergesort(s,0,n-1);
		printf("%I64d\n",t);
		delete s;
	}
	return 0;
}
