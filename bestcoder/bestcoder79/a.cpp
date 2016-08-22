#include<iostream>
using namespace std;
int t,a,b;
bool flag;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        flag=false;
        scanf("%d%d",&a,&b);
        int adu=180-360/a;
        int bdu=180-360/b;
        int na=360/adu+1;
        int nb=360/bdu+1;
        for(int i=0;i<=na;i++)
        {
            for(int j=0;j<=nb;j++)
            {
                if(i*adu+j*bdu==360)
                {
                    flag=true;
                }
            }
        }
        if(flag)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}