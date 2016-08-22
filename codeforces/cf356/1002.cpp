#include<cstdio>
#include<cstring>
#include<cmath>
int prime[15]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
bool query(int d)
{
    char res[4];
    printf("%d\n",d);
    scanf("%s",res);
    return res[0]=='y';
}
const char *str[2]={"prime","composite"};
int main()
{
    int i;
    if(query(2))
    {
        if(query(4)){puts(str[1]);}
        for(i=1;i<15 && !query(prime[i]);i++);
        puts(str[i!=15]);
    }
    else if(query(3))
    {
        if(query(9)){puts(str[1]);}
        for(i=2;i<15 && !query(prime[i]);i++);
        puts(str[i!=15]);
    }
    else if(query(5))
    {
        if(query(25)){puts(str[1]);}
        for(i=3;i<15 && !query(prime[i]);i++);
        puts(str[i!=15]);
    }
    else if(query(7))
    {
        if(query(49)){puts(str[1]);}
        for(i=4;i<15 && !query(prime[i]);i++);
        puts(str[i!=15]);
    }
    else puts(str[0]);
    fflush(stdout);
    return 0;
}
