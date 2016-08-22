#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<vector>
#include<cmath>
#pragma waring(disable:4996)
using namespace std;
double a,b,x,y,v;
int n;
const int inf=0x3f3f3f3f;
int main()
{
	double ans=inf;
	//freopen("input.txt","r",stdin);
    scanf("%lf%lf",&a,&b);
    scanf("%d",&n); 
    while(n--)
    {
        scanf("%lf%lf%lf",&x,&y,&v);
        double temp=(  sqrt(abs(a-x)*abs(a-x)*1.0+1.0*abs(b-y)*abs(b-y) ))/v;
        if(ans>temp)
            ans=temp;
    }
    printf("%lf\n",ans);
    return 0;
}
