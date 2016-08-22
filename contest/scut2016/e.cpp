#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100010
int n,a[maxn];
int main()
{

	int i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    bool button=true;
    for(i=1;i<n;i++)
    {
        if(a[i]%a[0]!=0)
        {
            button=false;
            break;
        }
    }
    if(button)
    {
        printf("%d\n",a[0]);
    }
    else
    {
        printf("-1\n");
    }
    return 0;
}
