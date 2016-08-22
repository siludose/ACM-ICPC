#include<iostream>  
#include<cmath>  
#include<algorithm>  
using namespace std;  
  
#define M 100010  
#define MAXN 500  
#define MAXM 500  
int dp[M][18];  
/* 
*һάRMQ ST�㷨 
*����RMQ���� makermq(int n,int b[]) O(nlog(n))���㷨���Ӷ� 
*dp[i][j] ��ʾ��i��i+2^j -1����С��һ��ֵ(��i��ʼ����2^j����) 
*dp[i][j]=min{dp[i][j-1],dp[i+2^(j-1)][j-1]} 
*��ѯRMQ rmq(int s,int v) 
*��s-v �ֳ�����2^k������ 
*�� k=(int)log2(s-v+1) 
*��ѯ���Ӧ��Ϊ min(dp[s][k],dp[v-2^k+1][k]) 
*/  
  
void makermq(int n,int b[])  
{  
    int i,j;  
    for(i=0;i<n;i++)  
        dp[i][0]=b[i];  
    for(j=1;(1<<j)<=n;j++)  
        for(i=0;i+(1<<j)-1<n;i++)  
            dp[i][j]=min(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);  
}  
int rmq(int s,int v)  
{  
    int k=(int)(log((v-s+1)*1.0)/log(2.0));  
    return min(dp[s][k],dp[v-(1<<k)+1][k]);  
}  
  
void makeRmqIndex(int n,int b[]) //������Сֵ��Ӧ���±�  
{  
    int i,j;  
    for(i=0;i<n;i++)  
        dp[i][0]=i;  
    for(j=1;(1<<j)<=n;j++)  
        for(i=0;i+(1<<j)-1<n;i++)  
            dp[i][j]=b[dp[i][j-1]] < b[dp[i+(1<<(j-1))][j-1]]? dp[i][j-1]:dp[i+(1<<(j-1))][j-1];  
}  
int rmqIndex(int s,int v,int b[])  
{  
    int k=(int)(log((v-s+1)*1.0)/log(2.0));  
    return b[dp[s][k]]<b[dp[v-(1<<k)+1][k]]? dp[s][k]:dp[v-(1<<k)+1][k];  
}  
  
int main()  
{  
    int a[]={3,4,5,7,8,9,0,3,4,5};  
    //�����±�  
    makeRmqIndex(sizeof(a)/sizeof(a[0]),a);  
    cout<<rmqIndex(0,9,a)<<endl;  
    cout<<rmqIndex(4,9,a)<<endl;  
    //������Сֵ  
    makermq(sizeof(a)/sizeof(a[0]),a);  
    cout<<rmq(0,9)<<endl;  
    cout<<rmq(4,9)<<endl;  
    return 0;  
}  