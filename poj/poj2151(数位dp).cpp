#include<iostream>
#include<string.h>
using namespace std;
int m,t,n;
double f[1010][35];
double g[1010][35][35];
void init()
{
    memset(g,0.0,sizeof(g));
    for(int i=1;i<=t;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%lf",&f[i][j]);
        }
    }
    for(int i=1;i<=t;i++)
    {
        g[i][1][1]=f[i][1];
        g[i][1][0]=1-f[i][1];
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    while(~scanf("%d%d%d",&m,&t,&n))
    {
        if(m==0&&t==0&&n==0)
            break;
        
        init();
        for(int i=1;i<=t;i++)
        {
            for(int j=2;j<=m;j++)
            {
                g[i][j][0]=g[i][j-1][0]*(1-f[i][j]);
                for(int k=1;k<=j;k++)
                {
                    g[i][j][k]=g[i][j-1][k-1]*f[i][j]+g[i][j-1][k]*(1-f[i][j]);
                }
            }
        }
        double sum=1;
        for(int i=1;i<=t;i++)
        {
            sum*=1-g[i][m][0];
        }
        double sum2=1;
        for(int i=1;i<=t;i++)
        {
            double temp=0;
            for(int k=1;k<n;k++)
            {
                temp+=g[i][m][k];
            }
            sum2*=temp;
        }
        printf("%.3f\n",sum-sum2);
    }

}