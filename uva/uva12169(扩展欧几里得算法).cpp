#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 1010
#define mod 10001
#define ll long long
int x[maxn];
int n;

void gcd(ll a,ll b,ll &d,ll &x,ll &y)
{
    if(!b){
        d=a;
        x=1;y=0;
        return;
    }
    else{
        gcd(b,a%b,d,y,x);
        y-=x*(a/b);
        return;
    }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<2*n;i+=2)
    {
        scanf("%lld",&x[i]);
    }
    ll a,b;
    for(a=0;;a++){
        ll k,b,d;
        ll t=(x[3]-a*a*x[1]);
        gcd(mod,a+1,d,k,b);
        if(t%d)continue;
        b=b*t/d;
        int yes=1;
        for(int i=2;i<=2*n;i++){
            if(i&1){
                if(x[i]!=((a*x[i-1]+b)%mod)){
                    yes=0;
                    break;
                }
            }
            else{
                x[i]=(a*x[i-1]+b)%mod;
            }
        }
        if(yes)
            break;
    }
    for(int i=2;i<=2*n;i+=2)
        printf("%lld\n",x[i]);
    return 0;
}
