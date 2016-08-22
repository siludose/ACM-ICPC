#include<iostream>
#include<cstdio>
#include<math.h>
using namespace std;
double d,h,v,e,s,t;
int main()
{
    scanf("%lf%lf%lf%lf",&d,&h,&v,&e);
    s=d*d/4*M_PI;
    if(e*s>=v)
    {
        printf("NO\n");return 0;
    }
    else
    {
        t=s*h/(v-e*s);
        if(t>10000)
        {
            printf("NO\n");
        }
        else
        {
            printf("YES\n");
            printf("%lf",t);
        }
    }
    return 0;
}
