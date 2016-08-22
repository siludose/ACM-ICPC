#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=50010;
int you[maxn],in[maxn],ran[maxn],add[maxn<<2],work[maxn<<2];
vector<int>to[maxn];
int num;
void init(int N)
{
    for(int i=1;i<=N;i++)
        to[i].clear();
    memset(in,0,sizoef(in));
    memset(you,0,sizoef(you));
    build(1,N,1);
}
void addedge(int u,int v)
{
    to[v].push_back(u);
    in[u]++;
}
int getrank(int beg)
{
    int index=num++;
    you[index]=index;
    ran[index]=beg;
    for(int i=0;i<to[beg].size();i++){
        you[i]=getrank(to[beg][i]);
    }
    return you[index];
}
void pushdown(int rt)
{
    if(add[rt])
    {
        work[rt<<1|1]=work[rt<<1]=add[rt];
        add[rt<<1|1]=add[rt<<1]=add[rt];
        add[rt]=0;
    }
}
 void build(int l,int r,int rt)
 {
    if(l==r){
        work[rt]=-1;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
 }
 void update(int l,int r,int rt,int L,int R,int v)
 {
    if(l>=L&&r<=R)
    {
        add[rt]=work[rt]=v;
        return;
    }
    pushdown(rt);
    int m=(l+r)>>1;
    if(m>=L)
        update(lson,L,R,v);
    if(m<R)
        update(rson,L,R,v);
 }
 int query(int l,int r,int rt,int index)
 {
    if(l==r)
    {
        return work[rt];
    }
    pushdown(rt);
    int m=(l+r)>>1;
    if(m>=L)
        return query(lson,index);
    else
        return query(rson,index);
 }
int main()
{
    int t,n,m,u,v,q,x,v;char s[10];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);init(n);
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            addedge(u,v);
        }
        int mark=0;
        for(int i=1;i<=N;i++){
            if(in[i]==0)
                mark=i;
        }
        num=1;
        you[1]=getrank(1);
        scanf("%d",&q);
        while(q--){
            scanf("%s",s);
            if(s[0]=='C'){
                scanf("%d",&x);
                printf("%d\n",query(1,n,1,x));
            }else if(s[0]=='T'){
                scanf("%d%d",&x,&v);
                int nn=ran[x];
                update(1,n,1,nn,you[nn],v);
            }
        }
    }
    return 0;
}