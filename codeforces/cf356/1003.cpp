#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long 
ll n;
int main()
{
    while(~scanf("%I64d",&n))
    {
        if(n<15)
        {
            n>=7?printf("7 7\n"):printf("%I64d %I64d\n",n,n); 
        }
        else if(n<23)
        {
            printf("8 15\n");
        }
        else if(n<42)
        {
            printf("9 23\n");
        }
        else if(n<50)
        {
            printf("9 42\n");
        }
        else if(n<69)
        {
            printf("10 50\n");
        }
        else if(n<77)
        {
            printf("10 69\n");
        }
        else
        {
            ll count=11;
            ll sum=77;
            ll mark;
            ll marksum;
            for(ll i=4;;i++)
            {
                if((sum+i*i*i)<=n)
                {
                    sum+=i*i*i;
                    count++;
                }
                else
                {
                    mark=i;
                    break;
                }
            }
            marksum=sum;
            for(ll i=2;i<mark;i++)
            {
                if((marksum-i*i*i+mark*mark*mark)<=n)
                {
                    sum=marksum-i*i*i+mark*mark*mark;
                    break;
                }
            }
            printf("%d %I64d\n",count,sum);
        }
    }
    return 0;
}
