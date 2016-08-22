#pragma warning(disable:4996)
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string.h>
#include<queue>
#include<set>
#define ll long long
#define maxn 101000
using namespace std;
int t,n,k;
multiset<ll>s;
ll a[maxn];
int l,r,mi,ma;
ll ans;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%I64d",&a[i]);
        }
        if(k==1)
        {
            printf("%d\n",n);continue;
        }
        l=1;r=2;
        s.insert(a[1]);
        ans=n;
        while(1)
        {
            
            if(!s.empty())
            {
				mi = *s.begin();
				ma = *s.rbegin();
                if(abs(a[r]-mi)<k&&abs(ma-a[r]<k))
                {
                    ans+=s.size();
                    s.insert(a[r]);
                    r++;
                    if(r>n)
                        break;
                }
                else
                {
                	if(!s.empty())
                    	s.erase(s.find(a[l]));
                    l++;
                }
            }
            else
            {
                l=r;
                s.insert(a[r]);
                r++;
                if(r>n)
                    break;
            }
        }
        s.clear();
        printf("%I64d\n",ans);
    }
    return 0;
}
