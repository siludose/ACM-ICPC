#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
const int MAX_N=500000+5;
int a[MAX_N];
int bit[MAX_N+1],n;
#define  ll long long
int sum(int i)
{
    int s=0;
    while (i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while (i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
void solve()
{
    ll ans=0;
    for (int j=n-1;j>0;j--)
    {
        ans+=sum(a[j]);
        add(a[j],1);
    }
    cout<<ans<<endl;
}
int main()
{
    while(cin>>n)
    {
        memset(bit,0,sizeof(bit));
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        solve();
    }    
    return 0;
}
