#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,a,b,numa,numb;
int main()
{
    scanf("%d",&t);
    numa=numb=0;
    while(t--)
    {
        scanf("%d%d",&a,&b);
        if(a>b){
            numa++;
        }else if(b>a){
            numb++;
        }else{
            numa++;numb++;
        }
    }
    if(numa>numb){
        printf("Mishka\n");
    }else if(numb>numa){
        printf("Chris\n");
    }else{
        printf("Friendship is magic!^^\n");
    }
    return 0;
}