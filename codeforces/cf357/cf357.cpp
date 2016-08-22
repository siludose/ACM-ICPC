#include <bits/stdc++.h>
using namespace std;
int n;
char s[60],a,b;
bool flag;
int main()
{
    flag=false;
    scanf("%d",&n);
    while(n--)
    {
        cin>>s;
        cin>>a>>b;
        if(a>=2400&&b>a)
        {
            flag=true;
        }
    }
    if(flag)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
