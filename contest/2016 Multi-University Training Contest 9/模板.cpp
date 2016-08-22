#pragma warning(dsaible:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
#define ll long long
using namespace std;
const int MAXN=4000; 
ll t,n,m,l,pro,k;
struct plant
{
	ll pay,t;
	ll val;	
}pp[MAXN];

bool cmp(struct plant a,struct plant b)
{
	if(a.t==b.t)
		return (a.val-a.pay)>(b.val-b.pay);
	return a.t<b.t;
}
void init(ll N)
{
	for (int i = 0; i <= N; i++)
	{
		pp[i].val = 0;
	}
}
int main()
{
	//freopen("input.txt","r",stdin);
    scanf("%lld",&t);
    for(int cas=1;cas<=t;cas++)
    {
		scanf("%lld%lld%lld", &n, &m, &l); init(n);
		for(int i=0;i<n;i++)
		{
			scanf("%lld%lld",&pp[i].pay,&pp[i].t);
		}
		for(int j=0;j<m;j++)
		{
			scanf("%lld %lld",&pro,&k);
			ll num;
			for(int i=0;i<k;i++)
			{
				scanf("%lld",&num);
				pp[num-1].val+=pro;
			}
		}	
		sort(pp,pp+k,cmp);
		ll ans = 0;ll  minday = -1;
		for(int i=0;i<k;i++)
		{
			if ((pp[i].val - pp[i].pay)>0)
				ans += pp[i].val - pp[i].pay;
			if(ans>=l)
			{
				minday = pp[i].t; break;
			}
		}
		if(minday==-1)
		{
			printf("Case #%d: impossible\n",cas);
			continue;
		}
		ans=0;
		for(int i=0;i<n;i++)
		{
			if(pp[i].t<=minday)
			{
				if ((pp[i].val - pp[i].pay)>0)
				{
					ans += pp[i].val - pp[i].pay;
				}
			}
		}
        printf("Case #%d: %lld %lld\n",cas,minday,ans);
    }
}






