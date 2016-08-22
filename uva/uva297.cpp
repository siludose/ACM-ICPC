#include<iostream>
#include <string.h>
#include <string>
#include <cstring>
#include<ctype.h>
using namespace std; 
const int maxn=1024;
int a1[maxn],a2[maxn];
int n,number;
int count[maxn]; 
int count_i;
int score;
int i,j;
int s_i;
string s;
void build(string  s,int a[maxn])
{
	i=0;
	s_i=0;
	number=maxn;
	while(s_i<s.size())
	{		
		if (s[s_i]=='p'){count_i++;number=number/4;}
		else if(s[s_i]=='e'){i+=number;count[count_i]++;}
		else
		{
			j=number;
			while(j--)
			{
				a[i++]=1;
			}
			count[count_i]++;
		}
		if (count[count_i]==4)
		{
			count[count_i]=0;
			count_i--;
			number=number*4;
		}
		s_i++;
	}
}
int main()
{
	cin>>n;
	while(n--)
	{
		
		memset(a1,0,sizeof(a1));
		memset(a2,0,sizeof(a2));


		memset(count,0,sizeof(count));
		count_i=0;
		cin>>s;
		build(s,a1);


		memset(count,0,sizeof(count));
		count_i=0;
		cin>>s;
		build(s,a2);

		score=0;
		for (int i=0;i<maxn;i++)
		{
			if (a1[i]||a2[i])
			{
				score++;
			}
		}
		cout<<"There are "<<score<<" black pixels."<<endl;
	}
}