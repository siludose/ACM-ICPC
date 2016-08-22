#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<vector> 
using namespace std;
#define ull unsigned long long 
int t,n;
ull a,b;
vector<int>fib[1010];
int m[1010];
ull quickpower(ull a, ull n,int mod) {
    if (n == 0)
        return 1;
    ull qp=quickpower(a, n / 2,mod);
    if (n % 2 == 1)
        return (qp * qp % mod) * a % mod;
    else
        return qp * qp % mod;
} 
int main()
{
	//freopen("input.txt","r",stdin);
    for(int i=2;i<=1000;i++)
    {
        fib[i].push_back(0);fib[i].push_back(1);
        for(int j=2;;j++)
        {
            fib[i].push_back((fib[i][j-1]%i+fib[i][j-2]%i)%i);
            if(fib[i][j-1]==0&&fib[i][j]==1)
            {
                m[i]=j-1;
                break;
            }
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu%llu%d",&a,&b,&n);
        if(a == 0 || n == 1) printf("0\n");
        else printf("%d\n",fib[n][quickpower(a%m[n],b,m[n])]);
    }
    return 0;
}
