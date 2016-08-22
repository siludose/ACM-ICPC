#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cstring>
using namespace std;
int n;
char s[5][20]={"I hate that ","I love that ","I hate it","I love it"};
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            if(i==n)
            {
                if(n%2==1)printf("%s\n",s[2]);
                else    printf("%s\n",s[3]);
            }
            else
            {
                if(i%2==1)printf("%s",s[0]);
                else printf("%s",s[1]);
            }
        }
    }
    return 0;
}
