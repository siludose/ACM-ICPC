#include<iostream>
#include<algorithm>
#include<string.h>

//#pragma warning(disable:4996)
using namespace std;
#define maxn 200010
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
int t,n;
int a[maxn],val[maxn*4];
int b[maxn];

void pushup(int rt)
{
    val[rt]=max(val[rt<<1],val[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    val[rt]=0;
    if(l==r)
    {
        return;
    }
    int m=(l+r)>>1;
    build(lson);
    build(rson);
}
void add(int l,int r,int rt,int temp,int num)
{
    if(l==r&&l==temp)
    {
        val[rt]=num;
        return;
    }
    int m=(l+r)>>1;
    if(temp<=m)
        add(lson,temp,num);
    else
        add(rson,temp,num);
    pushup(rt);
}
int query(int l,int r,int rt,int L,int R)
{
    if(l>=L&&r<=R)
    {
        return val[rt];
    }
    int m=(l+r)>>1;
    int temp=0;
    if(m>=L)
        temp=max(query(lson,L,R),temp);
    if(m<R)
        temp=max(query(rson,L,R),temp);
    return temp;
}
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
		build(1, n, 1);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
			b[i] = a[i];
        }
        sort(b,b+n);
        int size=unique(b,b+n)-b;
        for(int i=0;i<n;i++)
        {
            a[i]=lower_bound(b,b+size,a[i])-b+1;
        }
        for(int i=0;i<n;i++)
        {
			int num;
			if (a[i] == 1)
			{
				num = 1;
			}
			else
			{
				num = query(1, n, 1, 1, a[i] - 1) + 1;
			}           
            add(1,n,1,a[i],num);
            a[i]=num;
        }
        printf("%d",a[0]);
        for(int i=1;i<n;i++)
        {
            printf(" %d",a[i]);
        }
        printf("\n");
    }
    return 0;
}
