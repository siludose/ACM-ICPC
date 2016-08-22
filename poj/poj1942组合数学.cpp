#include<iostream>
#include<math.h>  
#include<iomanip> 
using namespace std;
int n,m;
double calcu(unsigned n,unsigned m)
{
    unsigned a=n+m;
    unsigned b=m<n?m:n;
    double sum=1.0;
    while(b>0)
        sum*=(double)(a--)/(double)(b--);
    return sum;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(m==0&&n==0)
        {
            break;
        }
        cout<<fixed<<setprecision(0)<<calcu(n,m)<<endl;
    }
    return 0;
}
