#include<iostream>
#include<string>
#include<string.h>
using namespace std;
char s[15];
int c[35][35]={0};
void play_table()
{
    for(int i=0;i<=32;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(!j||i==j)
            {
                c[i][j]=1;
            }
            else
            {
                c[i][j]=c[i-1][j-1]+c[i-1][j];
            }
        }
    }
    c[0][0]=0;
    return;
}
int main(int i)
{
	play_table();
	
    while(~scanf("%s",s))
    {
    	bool button=false;
        int len=strlen(s);

        for(i=1;i<len;i++)
        {
            if(s[i-1]>=s[i])
            {
                button=true;
            }
        }
		if(button)
		{
			cout<<0<<endl;
			continue;
		}
        int sum=0;
        for(i=1;i<len;i++)
        {
            sum+=c[26][i];
        }

        for(i=0;i<len;i++)
        {
            char ch=(!i)?'a':s[i-1]+1;
            while(ch<=s[i]-1)
            {
                sum+=c['z'-ch][len-1-i];
                ch++;
            }
        }
        cout<<sum+1<<endl;
    }
    return 0;
}
