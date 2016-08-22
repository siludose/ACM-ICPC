#include<iostream>
using namespace std;
int n,a,t[102];
int main()
{
    scanf("%d%d",&n,&a);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t[i]);
    }
    int sum=t[a];
    int left=a-1,right=a+1;
    while(1)
    {
        if(left>=1&&right<=n)
        {
            if(t[left]==1&&t[right]==1)
            {
                sum+=2;
            }
            left--;
            right++;
        }
        else if(left<1&&right>n)
        {
            break;
        }
        else if(left<1)
        {
            sum+=t[right++];
        }
        else if(right>n)
        {
            sum+=t[left--];
        }
    }
    printf("%d\n",sum);
    return 0;
}
