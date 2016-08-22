/* a 的  n 次方的快速幂，C 代码 */
const int mod=1000000007;
int quickpower(int a, int n) {
    if (n == 0)
        return 1;
    int qp=quickpower(a, n / 2);
    if (n % 2 == 1)
        return (long long)(qp * qp % mod) * a % mod;
    else
        return (long long)qp * qp % mod;
} 

long long result(long long a,long long b,long long m)
{
    long long d,t;

    d=1;
    t=a;
    while (b>0)
    {
        if (b%2==1)
            d=(d*t)%m;
        b/=2;
        t=(t*t)%m;
    }

    return d;
}


/*
使用过程
 */
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
#define ll long long
const ll mod=1000000007;
int a,n;
ll quickpower(ll a, ll n) {
    if (n == 0)
        return 1;
    ll qp=quickpower(a, n / 2);
    if (n % 2 == 1)
        return (qp * qp % mod) * a % mod;
    else
        return qp * qp % mod;
} 
int main()
{
    while(~scanf("%lld%lld",&a,&n))
    {
        printf("%lld\n",quickpower(a,n));
    }
    return 0;
}