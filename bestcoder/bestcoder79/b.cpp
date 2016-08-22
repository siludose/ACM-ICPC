#include<iostream>
using namespace std;
int t;
__int64 a,b,c,d;
int a[50],c[50]; 
void get(int a[],__int64 b)
{
	int num=0;
	while(b)
	{
		a[num]=b%2;
		b/=2;
	}
}
int main()
{
    scanf("%d",&t);
    while(t--)
	{
		scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d);
		
	} 
    return 0;
}
