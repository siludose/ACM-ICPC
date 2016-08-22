#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string.h>
#pragma warning(disable:4996)
#define rson  m+1,r,rt<<1|1
#define lson  l,m,rt<<1
using namespace std;
#define MAX_N 20010
vector<pair<int,int> >zone;
vector<int>abc;
int t,n,ans,c[MAX_N<<2],v[MAX_N<<2];
bool setv[MAX_N<<2],used[MAX_N];
void pushup(int rt)
{
    if(c[rt<<1]<=1&&c[rt<<1|1]<=1)
    {
        if(c[rt<<1]==0||c[rt<<1|1])
        {
            c[rt]=c[rt<<1]+c[rt<<1|1];
            v[rt]=v[rt<<1]+v[rt<<1|1];
        }
        else if(v[rt<<1]==v[rt<<1|1])
        {
            c[rt]=1;
            v[rt]=v[rt<<1];
        }
        else
        {
            c[rt]=2;
        }
    }
    else
    {
        c[rt]=c[rt<<1]+c[rt<<1|1];
    }        
}
void pushdown(int rt)
{
    c[rt<<1]=c[rt<<1|1]=c[rt];
    v[rt<<1]=v[rt<<1|1]=v[rt];
    setv[rt<<1]=setv[rt<<1|1]=setv[rt];
    setv[rt]=false;
}
void build(int l,int r,int rt)
{
    v[rt]=0;
    c[rt]=0;
	setv[rt] = 0;
    if(l==r)
    {
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}
void add(int l,int r,int rt,int L,int R,int val)
{
    if(setv[rt]==true)
    {
        pushdown(rt);
    }
    if(l>=L&&r<=R)
    {
        v[rt]=val;
        c[rt]=1;
        setv[rt]=true;
    }
    else
    {
        int m=(l+r)>>1;
        if(m>=L)
            add(lson,L,R,val);
        if(m<R)
            add(rson,L,R,val);
        pushup(rt);
    }
}
void query(int l,int r,int rt)
{
    if(c[rt]<=1)
    {
        if(c[rt]==1&&!used[v[rt]])
        {
            ans++;
            used[v[rt]]=true;
        }
    }
    else
    {
		int m = (l + r) >> 1;
        query(lson);
        query(rson);
    }
}
void solve()
{
    build(1,20000,1);
    for(int i=0;i<n;i++)
    {
        add(1,20000,1,zone[i].first,zone[i].second,i+1);
    }
    query(1,20000,1);
    cout<<ans<<endl;
	zone.clear();
	abc.clear();
	memset(used, 0, sizeof(used));
}
int main()
{
	freopen("input.txt", "r", stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        int a,b;
        ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            zone.push_back(make_pair(a,b));
        }
        for(int i=0;i<n;i++)
        {
            abc.push_back(zone[i].first);
            abc.push_back(zone[i].second);
        }
        sort(abc.begin(),abc.end());
        vector<int>::iterator iter=unique(abc.begin(),abc.end());
        abc.erase(iter,abc.end());
        for(int i=0;i<n;i++)
        {
            zone[i].first=lower_bound(abc.begin(),abc.end(),zone[i].first)-abc.begin()+1;
            zone[i].second=lower_bound(abc.begin(),abc.end(),zone[i].second)-abc.begin()+1;
        }
        solve();
    }
    return 0;
}
