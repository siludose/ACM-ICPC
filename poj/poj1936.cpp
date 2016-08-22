#include<iostream>
#include<string.h>
#include<cstring>
using namespace std;
#define N 100010
char a[N],b[N];
int main()
{
    while(~scanf("%s%s",a,b))
    {
        int lena=strlen(a);
        int lenb=strlen(b);
        int i=0,j=0;
        while(i<=lena&&j<=lenb)
        {
            if(a[i]==b[j])
            {
                i++;j++;
            }
            else
            {
                j++;
            }
        }
        if(i>lena)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}