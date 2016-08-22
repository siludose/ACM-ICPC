#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
const int MAXN=1000;
const int INF=0x3f3f3f3f;
int s[1100];
int num;

int pp()
{
    if(num<=20)
    {
    	int a=num;num=0;
        return s[a];      
    }
    else if(num<100)
    {
        int a=num/10*10;
        num=num%10;
        return s[a];
    }
    else if(num<1000)
    {
        int a=num/100;
        num=num%100;
        if(num!=0)
            return 7+s[a]+3;
        else
            return 7+s[a];
    }
    else
    {
    	num=0;
    	return 11;
	}
}

int main()
{
	s[1]=3;
	s[2]=3;
	s[3]=5;
	s[4]=4;
	s[5]=4;
	s[6]=3;
	s[7]=5;
	s[8]=5;
	s[9]=4;
	s[10]=3;
	s[11]=6;
	s[12]=6;
	s[13]=8;
	s[14]=8;
	s[15]=7;
	s[16]=7;
	s[17]=9;
	s[18]=8;
	s[19]=8;
	s[20]=6;
	s[30]=6;
	s[40]=5;
	s[50]=5;
	s[60]=5;
	s[70]=7;
	s[80]=6;
	s[90]=6;
	s[100]=7;
	s[1000]=11;
//    freopen("input.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int sum=0;
        for(int i=1;i<=n;i++)
        {
        	num=i;
        	while(num>0)
        	{
        		sum+=pp();
			}
		}
        printf("%d\n",sum);
    }
    return 0;
}
