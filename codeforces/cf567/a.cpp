#include<iostream>
#include<cstdio>
using namespace std;
#define maxn 100010 
int n,x[maxn];
int mi[maxn],ma[maxn];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);
    }
    for(int i=2;i<n;i++)
    {
        mi[i]=min(x[i]-x[i-1],x[i+1]-x[i]);
        ma[i]=max(x[i]-x[1],x[n]-x[i]);
    }
    mi[1]=x[2]-x[1];
    ma[1]=ma[n]=x[n]-x[1];
    mi[n]=x[n]-x[n-1];
    for(int i=1;i<=n;i++)
    {
        printf("%d %d\n",mi[i],ma[i]);
    }
    return 0;
}
