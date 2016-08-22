#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<queue>
#include<vector>
#include<stack>
using namespace std;
const int maxn=3000010;
int t,n,k,q;
int a[maxn],ran[maxn],dp[maxn],cp[maxn],s[maxn];
int main()
{
    //freopen("input.txt","r",stdin);
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&k,&q);
        int tmp=n,tot=0;
        s[0]=0;
        while(tmp){
            tot++;
            s[tot]=s[tot-1]+(tmp-1)/k+1;
            tmp-=(tmp-1)/k+1;
        }
        dp[0]=0;
        for(int i=0;i<n;i++){
            dp[i]=i%k?dp[i-i/k-1]+1:0;
            cp[i]=i%k?cp[i-i/k-1]:i/k+1;
        }
        for(int i=0;i<n;i++)
            ran[s[dp[i]]+cp[i]]=i;
		int x;
		for (int i = 0; i < q; i++){
			scanf("%d", &x);
			printf("%d\n", ran[x]+1);
		} 
    }
    return 0;
}
