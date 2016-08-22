#include<iostream>
#define min(a,b) a<b?a:b
using namespace std;
int t[6],sum,calcu[101],Min;
int main()
{
    sum=0;Min=10000;
    for(int i=0;i<5;i++)
    {
        scanf("%d",&t[i]);
        sum+=t[i];
        calcu[t[i]]++;
    }
    for(int i=0;i<=100;i++)
    {
        int res;
        if(calcu[i]==2)
        {
            res=sum-i*2;
            Min=min(Min,res);
        }
        else if(calcu[i]>2)
        {
            res=sum-i*3;
            Min=min(Min,res);
        }
        
    }
    printf("%d\n",min(Min,sum));
    return 0;
}
