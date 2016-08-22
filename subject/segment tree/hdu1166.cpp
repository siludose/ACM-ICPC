#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cmath>
using namespace std;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn=55555;
int sum[maxn<<2];
void pushup(int rt)
{
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%d",&sum[rt]);
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}
void update(int l,int r,int rt,int index,int v)
{
    if(l==r)
    {
        sum[rt]+=v;
        return;
    }
    int m=(l+r)>>1;
    if(m>=index)
        update(lson,index,v);
    else
        update(rson,index,v);
    pushup(rt);
    return;
}
int query(int l,int r,int rt,int L,int R)
{
    if(l>=L&&r<=R)
    {
        return sum[rt];
    }
    int m=(l+r)>>1;
    int ans=0;
    if(m>=L)
        ans+=query(lson,L,R);
    if(m<R)
        ans+=query(rson,L,R);
    return ans;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int t,x,y,n;
    char s[20];
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        build(1,n,1);
        printf("Case %d:\n",cas);
        while(scanf("%s",s)&&s[0]!='E'){//这里没有注意终止条件，使得他明明终止了程序还是想要输入，我真是太蠢了 
            scanf("%d%d",&x,&y);
            if(s[0]=='Q'){   
                printf("%d\n",query(1,n,1,x,y));
            }else if(s[0]=='A'){
                update(1,n,1,x,y);
            }else if(s[0]=='S'){
                update(1,n,1,x,-y);
            }else{
                break;
            }   
        }
    }
    return 0;
}
