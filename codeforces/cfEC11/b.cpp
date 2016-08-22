#include<iostream>
using namespace std;
int a[110],b[110],c[110],d[110];
int n,m;
int main(int i,int j)
{
    scanf("%d%d",&n,&m);
    int size=n*2;
    for(i=1,j=1;i<=size;i+=2,j++)
    {
        a[j]=i;
        //cout<<a[j]<<" ";
    }
    //cout<<endl;
    
    for(i=2,j=1;i<=size;i+=2,j++)
    {
        d[j]=i;
        //cout<<d[j]<<" ";
    }
    //cout<<endl;
    for(i=size+1,j=1;i<=size*2;i+=2,j++)
    {
        b[j]=i;
        //cout<<b[j]<<" ";
    }
    //cout<<endl;
    for(i=size+2,j=1;i<=size*2;i+=2,j++)
    {
        c[j]=i;
        //cout<<c[j]<<" ";
    }
    //cout<<endl;
    for(int i=1;i<=n;i++)
    {
        if(b[i]>0&&b[i]<=m)
        {
            cout<<b[i]<<" ";
        }
        if(a[i]>0&&a[i]<=m)
        {
            cout<<a[i]<<" ";
        }
        if(c[i]>0&&c[i]<=m)
        {
            cout<<c[i]<<" ";
        }
        if(d[i]>0&&d[i]<=m)
        {
            cout<<d[i]<<" ";
        }
    }
    return 0;
}
