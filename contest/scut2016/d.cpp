#include<iostream>
#include<cstdio>
#include<string.h>
#define max(a,b) a>b?a:b
using namespace std;
int t;
__int64 n,n1,n2;
struct BigInt
{
    int mod;
    int DLEN;
    int a[600],len;
    BigInt()
    {
        memset(a,0,sizeof(a));
        len=1;mod=10000;DLEN=4;
    }
    BigInt(__int64 v)
    {
        memset(a,0,sizeof(a));DLEN=4;mod=10000;
        len=0;
        do
        {
            a[len++]=v%mod;
            v/=mod;
        }while(v);
    }
    BigInt operator +(const BigInt &b)const
    {
        BigInt res;int i;
        res.len=max(len,b.len);
        for(i=0;i<=len;i++)
            res.a[i]=0;
        for(i=0;i<res.len;i++)
        {
            res.a[i]+=((i<len)?a[i]:0)+((i<b.len)?b.a[i]:0);
            res.a[i+1]+=res.a[i]/mod;
            res.a[i]%=mod;
        }
        if(res.a[res.len]>0)res.len++;
        return res;
    }
    BigInt operator*(const BigInt &b)const
    {
        BigInt res;int i;int j;
        for(i=0;i<len;i++)
        {
            int up=0;
            for(j=0;j<b.len;j++)
            {
                int temp=a[i]*b.a[j]+res.a[i+j]+up;
                res.a[i+j]=temp%mod;
                up=temp/mod;
            }
            if(up!=0)
                res.a[i+b.len]=up;
        }
        res.len=len+b.len;
        while(res.a[res.len-1]==0&&res.len>1)res.len--;
        return res;
    }
    void output()
    {
        printf("%d",a[len-1]);
        for(int i=len-2;i>=0;i--)
            printf("%04d",a[i]);
        printf("\n");
    }
};
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%I64d",&n);
        n1=n2=n/2;
        if(n%2==1)
        {
            n2++;
        }
        BigInt ans1;
        BigInt temp1;
        BigInt ans2;
        BigInt temp2;
        if(n1%2==0)
        {
            ans1=BigInt(n1/2);
            temp1=BigInt(n1-1);
        }
        else
        {
            ans1=BigInt(n1);
            temp1=BigInt((n1-1)/2);
        }
        ans1=ans1*temp1;
        if(n2%2==0)
        {
            ans2=BigInt(n2/2);
            temp2=BigInt(n2-1);
        }
        else
        {
            ans2=BigInt(n2);
            temp2=BigInt((n2-1)/2);
        }
        ans2=ans2*temp2;
        
        ans1=ans1+ans2;
        ans1.output();
    }
    return 0;
}
