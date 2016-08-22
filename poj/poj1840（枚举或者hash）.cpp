#include<iostream>
using namespace std;
int a,b,c,d,e,q1,q2,q3,q4,q5;
#define MAXHASHSIZE 31250010
short head[MAXHASHSIZE*2];
int main()
{
	//freopen("input.txt","r",stdin);
    while(~scanf("%d%d%d%d%d",&a,&b,&c,&d,&e))
    {
        long long res=0;
        for(q1=-50;q1<=50;q1++)
        {
            for(q2=-50;q2<=50;q2++)
            {
                if(q1!=0&&q2!=0)
                {
                    int tmp=a*q1*q1*q1+b*q2*q2*q2+MAXHASHSIZE;
                    head[tmp]++;
                }
            }
        }
        for(q3=-50;q3<=50;q3++)
        {
            for(q4=-50;q4<=50;q4++)
            {
                for(q5=-50;q5<=50;q5++)
                {
                    if(q3!=0&&q4!=0&&q5!=0)
                    {
                        int tmp=-(c*q3*q3*q3+d*q4*q4*q4+e*q5*q5*q5)+MAXHASHSIZE;
                        res+=head[tmp];
                    }
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
