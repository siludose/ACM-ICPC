#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
const int maxn=100100;
int n,a[maxn],q,x;
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&x);
        int temp=upper_bound(a,a+n,x)-a;
        printf("%d\n",temp);
    }
    return 0;
}
