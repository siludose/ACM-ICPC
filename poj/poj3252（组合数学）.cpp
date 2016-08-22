#include<iostream>
using namespace std;
int c[33][33];
int bin[35];
void play_table()
{
    for(int i=0;i<=32;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!j||i==j)
            {
                c[i][j]=1;
            }
            else
            {
                c[i][j]=c[i-1][j-1]+c[i-1][j];
            }
        }
    }
    return;
}
void dec_to_bin(int n)
{
    bin[0]=0;
    while(n)
    {
        bin[++bin[0]]=n%2;
        n/=2;
    }
    return;
}
int round(int n)
{
    int i,j;
    int sum=0;
    dec_to_bin(n);

    for(i=1;i<bin[0]-1;i++)
    {
        for(j=i/2+1;j<=i;j++)
        {
            sum+=c[i][j];
        }
    }
    int zero=0;
    for(i=bin[0]-1;i>=1;i--)
    {
        if(bin[i])
        {
            for(j=(bin[0]+1)/2-(zero+1);j<=i-1;j++)
            {
                sum+=c[i-1][j];
            }
        }
            
        else
        {
            zero++;
        }
    }
    return sum;
}
int main()
{
    play_table();
    
    int a,b;
    cin>>a>>b;
    cout<<round(b+1)-round(a)<<endl;

    return 0;
}
