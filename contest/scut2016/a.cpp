#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
char s[210];
int a[200];
int main()
{
	//freopen("input.txt","r",stdin);
    while(~scanf("%s",s))
    {
        int len=strlen(s);
        int i=len-1;
        for(;i>=0;i--)
            if(s[i]<'0'||s[i]>'9')
                break;
        int mark=i;i++;
		for(int j=0;j<=mark;j++)
        {
            printf("%c",s[j]);
        }
		if(mark==len-1)
		{
			printf("1\n");
			continue;
		}
		bool button=true;
		for(j=len-1;j>mark;j--)
		{
			if(button)
			{
				if(s[j]=='9')
				{
					s[j]='0';
					if((j-1)==mark)
					{
						printf("1");
					}						
				}
				else
				{
					s[j]++;
					button=false;
				}
			}
			else
			{
				break;
			}			
		}
		for(j=mark+1;j<len;j++)
		{
			printf("%c",s[j]);
		}
		printf("\n");
    }
    return 0;
}
