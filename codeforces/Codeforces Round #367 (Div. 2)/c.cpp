#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
#define maxn 110000
#define ll long long
const ll inf= 0x7f7f7f7f7f7f7f7f;
int n,a[maxn];
char s[10][maxn];
char b[10][maxn];
ll dp[maxn][2];
bool flag;
int main()
{
    //freopen("input.txt","r",stdin);
    memset(dp,0x7f,sizeof(dp));
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    scanf("%s",s[0]);
    int len=strlen(s[0]);
    for(int i=0;i<len;i++)
        b[0][i]=s[0][len-1-i];
    b[0][len]='\0';
    dp[0][0]=0;dp[0][1]=a[0];
    flag=true;
    for(int i=1;i<n;i++)
    {
        int now=(i+10)%10;
        int last=(i+10-1)%10;
        scanf("%s",s[now]);
        if(flag)
        {
            len=strlen(s[now]);
            for(int j=0;j<len;j++)
                b[now][j]=s[now][len-1-j];
            b[now][len]='\0';
            if(dp[i-1][0]!=inf)
            {
                if(strcmp(s[now],s[last])>=0)
                    dp[i][0]=min(dp[i][0],dp[i-1][0]);
                if(strcmp(b[now],s[last])>=0)
                    dp[i][1]=min(dp[i][1],dp[i-1][0]+a[i]);
            }
            if(dp[i-1][1]!=inf)
            {
                if(strcmp(s[now],b[last])>=0)
                    dp[i][0]=min(dp[i][0],dp[i-1][1]);
                if(strcmp(b[now],b[last])>=0)
                    dp[i][1]=min(dp[i][1],dp[i-1][1]+a[i]);
            }
            if(dp[i][1]==inf&&dp[i][0]==inf)
                flag=false;
        }
    }
	if (flag)
		printf("%I64d\n", min(dp[n - 1][0], dp[n - 1][1]));
	else
		printf("-1\n");
    return 0;
}
