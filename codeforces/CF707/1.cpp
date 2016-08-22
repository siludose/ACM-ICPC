#include<iostream>
#include<cstdio>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int n,m;
char co[10];
int main()
{
    bool flag=false;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=(n*m);i++)
    {
        scanf("%s",co);
        if(co[0]=='W'||co[0]=='B'||co[0]=='G')
            continue;
        else
            flag=true;
    }
    if(!flag)
        printf("#Black&White\n");
    else
        printf("#Color\n");
    return 0; 
}
