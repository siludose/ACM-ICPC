#include<iostream>
#include<string.h>
#include<cstring>
#include<queue>
#include<cmath>
using namespace std;
char s[10010][18];
char b[20];
int lena[10010];
queue<int>que;
int main()
{
	//freopen("input.txt","r",stdin);
    int num=0;
    while(1)
    {
        scanf("%s",s[num++]);
        if(s[num-1][0]=='#')
        {
            break;
        }
        lena[num-1]=strlen(s[num-1]);
    }
    while(1)
    {
        scanf("%s",b);
        if(b[0]=='#')
        {
            break;
        }
        int lenb=strlen(b);
        int mark=-1;
        bool flag=false;
        for(int i=0;i<num-1&&(!flag);i++)
        {          
            if(abs(lena[i]-lenb)<=1)
            {
                if(lena[i]==lenb)
                {
                    int differ=0;int j=0;
                    for(;j<lenb;j++)
                    {
                        if(b[j]!=s[i][j])
                        {
                            differ++;
                        }
                        if(differ==2)
                        {
                            break;
                        }
                    }
                    if(j==lenb)
                    {
                        if(differ==0)
                        {
                            flag=true;
                        }
                        else
                        {
                            mark=i;
                            que.push(i);
                        }
                    }
                }
                else
                {
                    if(lena[i]>lenb)
                    {
                        int ia=0,ib=0;
                        while(ia<lena[i]&&ib<lenb)
                        {
                            if(s[i][ia]!=b[ib])
                            {
                                ia++;
                            }
                            else
                            {
                                ib++;ia++;
                            }
                        }
                        if(ia==ib||ia-ib==1)
                        {
                            mark=i;
                            que.push(i);
                        }
                    }
                    else
                    {
                        int ia=0,ib=0;
                        while(ia<lena[i]&&ib<lenb)
                        {
                            if(s[i][ia]!=b[ib])
                            {
                                ib++;
                            }
                            else
                            {
                                ib++;ia++;
                            }
                        }
                        if(ia==ib||ib-ia==1)
                        {
                            mark=i;
                            que.push(i);
                        }
                    }
                }
            }
        }
        if(flag)
        {
            printf("%s is correct\n",b);
            while(!que.empty())
            {
            	que.pop();
			}
        }
        else if(mark!=-1)
        {
            printf("%s:",b);
            while(!que.empty())
            {
            	printf(" %s",s[que.front()]);
            	que.pop();
			}
			printf("\n");
        }
        else
        {
        	printf("%s:\n",b);
		}
    }
    return 0;
}
