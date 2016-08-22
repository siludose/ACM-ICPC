#pragma comment(linker, "/STACK:1024000000,1024000000")
#pragma  warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<stack>
#include<string.h>
#include<cmath>
using namespace std;
#define ll long long
#define mod 1000000007
#define inf 0x3f3f3f3f
#define maxn 100010
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int sum[maxn<<2],pre[maxn<<2],suf[maxn<<2];
int a[maxn];
void pushup(int rt,int len)
{
    sum[rt]=max(suf[rt<<1]+pre[rt<<1|1],max(sum[rt<<1],sum[rt<<1|1]));
    pre[rt]=pre[rt<<1];
    suf[rt]=suf[rt<<1|1];
    if(pre[rt<<1]==(len-(len>>1)))pre[rt]=pre[rt<<1]+pre[rt<<1|1];
    if(suf[rt<<1|1]==(len>>1))suf[rt]=suf[rt<<1]+suf[rt<<1|1];
    sum[rt]=max(sum[rt],max(pre[rt],suf[rt]));
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]=suf[rt]=pre[rt]=1;
        return ;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt,r-l+1);
}
void update(int l,int r,int rt,int index,int v)
{
    if(l==r)
    {
        sum[rt]=suf[rt]=pre[rt]=v;
        return ;
    }
    int m=(l+r)>>1;
    if(m>=index)
        update(lson,index,v);
    else
        update(rson,index,v);
    pushup(rt,r-l+1);
}
int query(int l,int r,int rt,int index)
{
    if(l==r)
        return sum[rt];
    int m=(l+r)>>1;
    if(index<=m){
        if(index+suf[rt<<1]>m)return suf[rt<<1]+pre[rt<<1|1];
        else return query(lson,index);
    }else{
        if(m+pre[rt<<1|1]>=index)return pre[rt<<1|1]+suf[rt<<1];
        else return query(rson,index);
    }
}
int main()
{
    int n,m,x;
    char s[10];
    stack<int> st;
    //freopen("input.txt","r",stdin);
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        build(1,n,1);
        while(!st.empty())st.pop();
		while (m--){
			scanf("%s", s);
			if (s[0] == 'D') {
				scanf("%d", &x);
				st.push(x);
				update(1, n, 1, x, 0);
			}
			else if (s[0] == 'R') {
				if (!st.empty()) {
					x = st.top();
					st.pop();
					update(1, n, 1, x, 1);
				}
			}
			else if (s[0] == 'Q') {
				scanf("%d", &x);
				printf("%d\n", query(1, n, 1, x));
			}
		}   
    }
	return 0;
}
