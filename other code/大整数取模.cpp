#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cstring>
char n[120];int m;
//分母必须是不超过int 
int main()
{
    while(~scanf("%s%d",n,&m))
    {
        int len=strlen(n);
        long long ans=0;
        for(int i=0;i<len;i++)
        {
            ans=((ans*10+n[i]-'0')%m);
        }
         printf("%lld\n",ans);
    }
    return 0;
}
