#include<iostream>
#include<cstdio>
#define ll long long
using namespace std;
ll n,a,b,p,q,pay;
ll lcm(ll a,ll b)
{
    ll c,m=a*b;
    while(b!=0)
    {
        c=a%b;a=b;b=c;
    }
    return m/a;
}
int main()
{
    while(cin>>n>>a>>b>>p>>q)
    {
        ll t1=n/a;
        ll t2=n/b;
        ll t3=n/lcm(a,b);;
        if(p>q)
        {
            pay=t1*p+(t2-t3)*q;
        }
        else
        {
            pay=(t1-t3)*p+t2*q;
        }
        cout<<pay<<endl;
    }
    return 0;
}
