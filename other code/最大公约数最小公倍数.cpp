#include<iostream>
#inlcude<cstdio>
int a,b,m,n,t,c;
using namespace std;
int lcd(int a,int b)
{
    int c;
    while(b!=0)
    {
        c=a%b;a=b;b=c;
    }
    return a;
}
int lcm(int a,int b)
{
    int c,m=a*b;
    while(b!=0)
    {
        c=a%b;a=b;b=c;
    }
    return m/a;
}