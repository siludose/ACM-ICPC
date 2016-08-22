/*
这道题目有需要贪心的部分，就是要先按身高排序，从小到大遍历一次
一个个插入，用线段树维护是否还有位置
可以放前面时放前面，这就是贪心
 */
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cmath>
#pragma warning(disable:4996)
using namespace std;
#define maxn 100100
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define inf 0x3f3f3f3f
int val[maxn<<2];
struct pp
{
    int tall;
    int num;
}p[maxn];
int ans[maxn];
bool cmp(struct pp a,struct pp b)
{
    return a.tall<b.tall;
}
int t,n;
void pushup(int rt)
{
    val[rt]=val[rt<<1]+val[rt<<1|1];
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        val[rt]=1;
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
int query1(int l,int r,int rt,int num)
{
    if(l==r)
        return l;
    int m=(l+r)>>1;
    if(val[rt<<1]>=num)
        return query1(lson,num);
    else
        return query1(rson,num-val[rt<<1]);
}
int query2(int l,int r,int rt,int num)
{
    if(l==r)
        return l;
    int m=(l+r)>>1;
    if(val[rt<<1|1]>=num)
        return query2(rson,num);
    else
        return query2(lson,num-val[rt<<1|1]);
}
void update(int l,int r,int rt,int index)
{
    if(l==r)
    {
        val[rt]=0;return;
    }
    int m=(l+r)>>1;
    if(m>=index)
        update(lson,index);
    else
        update(rson,index);
    pushup(rt);
}
int main()
{
	//freopen("input.txt","r",stdin);
    scanf("%d",&t);  
    for(int cas=1;cas<=t;cas++)
    {
    	memset(val,0,sizeof(val));
    	bool flag=true;
        scanf("%d",&n);
        build(1,n,1);
        for(int i=0;i<n;i++)
            scanf("%d%d",&p[i].tall,&p[i].num);
        sort(p,p+n,cmp);
        for(int i=0;i<n;i++)
        {
            int pos1=inf;int pos2=inf;
            if(val[1]>=(p[i].num+1))
            {
                pos1=query1(1,n,1,p[i].num+1);
                pos2=query2(1,n,1,p[i].num+1);
            }
            if((pos1==inf)&&(pos2==inf))
            {
                flag=false;break;
            }
            if(pos1<=pos2)
            {
                update(1,n,1,pos1);
                ans[pos1]=p[i].tall;
            }  
            else
            {
                update(1,n,1,pos2);
                ans[pos2]=p[i].tall;
            }  
        }
        if(flag)
        {
            printf("Case #%d: ",cas);
            for(int i=1;i<=n-1;i++)
                printf("%d ",ans[i]);
            printf("%d\n",ans[n]);
        }
        else
        {
            printf("Case #%d: impossible\n",cas);
        }
    }     
    
    return 0;
}
