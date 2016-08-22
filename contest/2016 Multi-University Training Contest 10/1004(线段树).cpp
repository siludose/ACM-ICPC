#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
const int maxn=3000010;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int t,n,k,q;
int num[maxn];
int ran[maxn];
int sum[maxn<<2];
void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        sum[rt]=1;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
int modify(int l,int r,int rt,int  index)
{
    if(l==r){
        sum[rt]=0;
        return l;
    }
    int m=(l+r)>>1;
    int temp;
    if(sum[rt<<1]>=index)
        temp=modify(lson,index);
    else
        temp=modify(rson,index-sum[rt<<1]);/
    pushup(rt);
    return temp;
}
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&n,&k,&q);
        build(1,n,1);
        int mark=1;
        int next=1;
        while(mark<=q){
            ran[mark++]=modify(1,n,1,next);
            next+=k-1;
            if(next>(n-mark+1))
                next=1;
        }
        int x;
        for (int i = 1; i <= q; i++) {
            scanf("%d",&x);
            printf("%d\n", ran[x]);
        }
    }
    return 0;
}
