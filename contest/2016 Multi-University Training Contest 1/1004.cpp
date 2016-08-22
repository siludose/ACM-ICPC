#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
#define maxn 1000100
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define ll long long
int t,n,m,num,l,r,a[maxn];
int gcd[maxn<<2];
map<ll,ll> mp1;
map<ll,ll> mp2;
map<ll,ll> ans;
int lcd(int a,int b)
{
    int c;
    while(b!=0)
    {
        c=a%b;a=b;b=c;
    }
    return a;
}
void pushup(int rt)
{
    gcd[rt]=lcd(gcd[rt<<1],gcd[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        gcd[rt]=a[num++];
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
ll query(int l,int r,int rt,int L,int R)
{
    if(l>=L&&r<=R)
    {
        return gcd[rt];
    }
    int m=(l+r)>>1;
    if(m>=L&&m<R)
    {
        return lcd(query(lson,L,R),query(rson,L,R));
    }
    else if(m>=L)
    {
        return query(lson,L,R);
    }
    else if(m<R)
    {
        return query(rson,L,R);
    }
}

int main()
{
	//freopen("input.txt", "r", stdin);
    scanf("%d",&t);
    int countt=0;
    while(t--)
    {
    	ans.clear();
    	mp1.clear();
    	mp2.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        mp1[a[1]]++;
        ans[a[1]]++;
        map<ll,ll>::iterator it;
        for(int i=2;i<=n;i++)
        {
            ll now=a[i];
            mp2[now]++;
            ans[now]++;
            for(it=mp1.begin();it!=mp1.end();it++)
            {
                int nex=lcd(now,it->first);
                ans[nex]+=it->second;
                mp2[nex]+=it->second;
            }
            mp1.clear();
            mp1=mp2;
            mp2.clear();
        }
        num=1;
        build(1,n,1);
        printf("Case #%d:\n",++countt);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d",&l,&r);
            ll temp=query(1,n,1,l,r);
            printf("%I64d %I64d\n",temp,ans[temp]);
        }
    }
    return 0;
}
