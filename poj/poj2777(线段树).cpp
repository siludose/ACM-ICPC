#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
#include<string.h>
#pragma warning(disable:4996)
#define rson  m+1,r,rt<<1|1
#define lson  l,m,rt<<1
using namespace std;
#define MAX_N 400000
int size_,t,o,ans,c[MAX_N<<4],v[MAX_N<<4];
bool setv[MAX_N<<4];
void pushup(int rt)
{
    if(c[rt<<1]<=1&&c[rt<<1|1]<=1)
    {
		if(v[rt<<1]==v[rt<<1|1])
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
    
    setv[rt] = 0;
    if(l==r)
    {
		v[rt] = 1;
		c[rt] = 1;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
	pushup(rt);
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
int query(int l,int r,int rt, int L, int R)
{
	if (setv[rt] == true)
	{
		pushdown(rt);
	}
    if(c[rt]<=1&&l>=L&&r<=R)
    {
        if(c[rt]==1)
        {
			ans |= v[rt];
        }
    }
    else
    {		
        int m = (l + r) >> 1;
		if (m >= L)
			ans|=query(lson,L,R);
		if (m<R)
			ans|=query(rson,L,R);
    }
	return ans;
}
int fenjie(int x) 
{
	int ans = 0;
	while (x) {
		if (x % 2)
			ans++;
		x /= 2;
	}
	return ans;
}
int main()
{
	//freopen("input.txt","r",stdin);
    while(scanf("%d%d%d",&size_,&t,&o)!=EOF)
    {
        build(1,size_,1);
		char a[10]; int l, r, value; ans = 0;
        for(int i=0;i<o;i++)
        {
        	scanf("%s",&a);
	        if(a[0]=='C')
	        {
	            scanf("%d%d%d",&l,&r,&value);
				if (l > r)
				{
					int tmp = l;
					l = r;
					r = tmp;
				}
	            add(1,size_,1,l,r,1<<(value-1));
	        }
	        else if(a[0]=='P')
	        {
	            scanf("%d%d",&l,&r);
				if (l > r)
				{
					int tmp = l;
					l = r;
					r = tmp;
				}            
	            cout<<fenjie(query(1,size_,1,l,r))<<endl;
				ans = 0;
	        }
		}      
    }

	return 0;

}
