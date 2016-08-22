#include<iostream>
#include<cstdio>
using namespace std;
int n,x,y;
int c[32001];
int a[15010];
void add(int num)
{
    while(num<=32001)
    {
        c[num]++;
        num+=num&(-num);
    }
}
int sum(int num)
{
    int sum=0;
    while(num>0)
    {
        sum+=c[num];
        num-=num&(-num);
    }
    return sum;
}
int main()
{
	//freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        a[sum(x+1)]++;
        add(x+1);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
    return 0;
}
