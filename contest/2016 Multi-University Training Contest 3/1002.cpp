#include<iostream>
#include<cstdio>
using namespace std;
int n,x;double sum;
int main()
{
    //freopen("input.txt","r",stdin);
    while(~scanf("%d",&n))
    {

        sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            if(i==1||i==n)
            {
                sum+=x*0.5;
            }
            else
            {
                sum+=x/3.0;
            }
        }
        if(n==1)
        {
            printf("%.6lf\n",x*1.0);
        }
        else
        {
            printf("%.6lf\n",sum);
        }
        
    }
    
    return 0;
}
