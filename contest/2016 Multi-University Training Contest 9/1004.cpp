#pragma warning(dsaible:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int t,n;
int main()
{
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        int start=3*(n+6)-n;
        int end=3*(n+6)-1;
        printf("%d",start);
        for(int i=start+1;i<=end;i++)
        {
            printf(" %d",i);
        }
        printf("\n");
    }
}
