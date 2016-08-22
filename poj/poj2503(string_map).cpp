#include<iostream>
#include<cstdio>
#include<map>
#include<string.h>
#include<string>
using namespace std;
    map<string,string>ma;
int main()
{
	//freopen("input.txt","r",stdin);
    char a[30],b[15],c[15];
    while(gets(a)&&a[0]!='\0')
    {
        sscanf(a,"%s%s",&b,&c);
        ma[c]=b;
    }
    char s[15];
    while(gets(s)&&s[0]!='\0')
    {
        if(ma[s][0]=='\0')cout<<"eh"<<endl;
        else cout<<ma[s]<<endl;
    }
    return 0;
}

