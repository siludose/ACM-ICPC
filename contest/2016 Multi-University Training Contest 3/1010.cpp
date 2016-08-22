#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a,v1,v2;
int main()
{
    while(~scanf("%d%d%d",&a,&v1,&v2))
    {
        if(a==0)
        {
            double ans=0;
            printf("%.12lf\n",ans);continue;
        }
        if(v1<=v2)
        {
            printf("Infinity\n");continue;
        }
        else
        {
            printf("%.12lf\n",v1*a*1.0/(v1*v1-v2*v2));
        }
    }
    return 0;
}