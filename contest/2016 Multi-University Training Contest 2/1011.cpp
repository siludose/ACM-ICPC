#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define maxn 100010
int t,n;
int a[maxn];
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        int number=0;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]%2==1)
            {
                number++;
            }
            sum+=a[i];
        }
        if(number==0)
        {
            printf("%d\n",sum);
        }
        else
        {
            if(sum-number==0)
            {
                printf("%d\n",1);
            }
            else
            {
                printf("%d\n",(sum-number)/(number*2)*2+1);
            }
        }
    }
    return 0;
}
