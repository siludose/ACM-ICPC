#include<iostream>  
#include<cstring>  
#include<queue>  
#include<cstdio>  
#include<cmath>  
#include<algorithm> 
#pragma warning(disable:4996)
#define N 55  
#define inf 1<<29  
#define MOD 9973  
#define LL long long  
#define eps 1e-7  
#define zero(a) fabs(a)<eps  
#define equal(a,b) zero(a-b)  
using namespace std;  
int dp[10][3];  
//dp[i][0],表示不存在不吉利数字  
//dp[i][1],表示不存在不吉利数字，且最高位为2  
//dp[i][2],表示存在不吉利数字  
void Init(){  
    memset(dp,0,sizeof(dp));  
    dp[0][0]=1;  
    for(int i=1;i<=6;i++){   
        dp[i][0]=dp[i-1][0]*9-dp[i-1][1];  //在最高位加上除了4之外的9个数字，但是可能在2之前加了6  
        dp[i][1]=dp[i-1][0];    //就是在原先不含不吉利数字的最高位加2  
        dp[i][2]=dp[i-1][2]*10+dp[i-1][0]+dp[i-1][1];  //在已经有不吉利数字最高位加任意数字，或者在无吉利数字前加4，或者在2前面加4  
    }  
}  
int slove(int n){  
    int len=0,bit[10];  
    int tmp=n;  
    while(n){  
        bit[++len]=n%10;  
        n/=10;  
    }  
    bit[len+1]=0;  
    int ans=0;  
    bool flag=false;  
    for(int i=len;i;i--){  
        ans+=dp[i-1][2]*bit[i];    
        if(flag)   //高位已经出现4或者62，后面的就随意  
            ans+=dp[i-1][0]*bit[i];  
        if(!flag&&bit[i]>4)  //高位可能出现4的情况  
            ans+=dp[i-1][0];  
        if(!flag&&bit[i+1]==6&&bit[i]>2)  //高位是6，后面一位可能出现2，这步debug了很久  
            ans+=dp[i][1];  
        if(!flag&&bit[i]>6)  //高位可能出现6，要把后面最高位为2计入  
            ans+=dp[i-1][1];  
        if(bit[i]==4||(bit[i+1]==6&&bit[i]==2))  //高位已经出现4或者62  
            flag=true;  
    }  
    return tmp-ans;  
}  
int main(){  
    int l,r;  
    Init();  
    while(scanf("%d%d",&l,&r)!=EOF&&l+r)  
        printf("%d\n",slove(r+1)-slove(l));  
    return 0;  
}  