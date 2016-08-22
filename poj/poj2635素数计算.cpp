#include<iostream>
#include<cstring>
#include<string.h>
#include<math.h>
#include<cmath>
//#pragma warning(disable:4996)
#define N 1001000
using namespace std;
long prime[N] = {0},num_prime = 0;      
int isNotPrime[N] = {1, 1};   
char s[200];
int k[100];
int a,pk,ps,lenk,re,temp;
void play_table()
{
	for(long i = 2 ; i < N ; i ++)         
    {              
        if(! isNotPrime[i])
		{
			prime[num_prime ++]=i; 
		}                              
            
        for(long j = 0 ; j < num_prime && i * prime[j] <  N ; j ++)  
        {                 
            isNotPrime[i * prime[j]] = 1;    
            if( !(i % prime[j] ) )                                 
			{
				break; 
			}               
        }          
    } 
}
int calcu()
{
	int i=0;
	int min_prime=0;
	while(min_prime==0)
	{
		if (prime[i] > a)
		{
			min_prime = a + 1;
		}
		pk=1;re=0,temp=0;
		while(pk<=lenk)
		{
			temp=re*1000+k[pk];
			re=temp%prime[i];
			pk++;
		}
		if(re==0)
		{
			min_prime=prime[i];
		}
		i++;
	}
	if(min_prime>=a)
	{
		return -1;
	}
	else
	{
		return min_prime;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	play_table();
	while(cin>>s>>a)
	{
		memset(k, 0, sizeof(k));
		if(s[0]=='0'&&a==0)
			break;
		int len=strlen(s);
		if(len%3!=0)
			lenk=len/3+1;
		else
			lenk=len/3;
		ps=len-1;
		pk=lenk;
		int count=0;
		while(ps>=0)
		{
			k[pk]+=(s[ps]-'0')*pow(10.0,(count%3));
			count++; ps--;		
			if(count%3==0)
				pk--;
		}
		int res=calcu();
		if(res==-1)
		{
			printf("GOOD\n");
		}
		else
		{
			printf("BAD %d\n",res);
		}
	}
	return 0;
}
