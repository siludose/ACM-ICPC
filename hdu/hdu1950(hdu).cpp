#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 40100
using namespace std;
int t,n,len,pos;
int a[maxn],b[maxn];
int search(int num, int low,int high)
{
    int mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(num>=b[mid]) low=mid+1;
        else    high=mid-1;
    }
    return low;
}
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        len=1;b[1]=a[1];
        for(int i=2;i<=n;i++)
        {
            if(a[i]>=b[len])
            {
                len++;
                b[len]=a[i];
            }
            else
            {
                pos=search(a[i],1,len);
                b[pos]=a[i];
            }
        }
        printf("%d\n",len);
    }
    return 0;
}
