#include<iostream>
#include<cstdio>
#include<string.h>
#include<stack>
#pragma warning(disable:4996)
using namespace std;
#define maxn 1000010
int t;
char s[maxn];
int A,B;
bool opena,openb;
int start,countt;
int ml,mr,mcount;
int len;
stack<char> st;
struct Vis
{
	int l;
	int co;
}vis[maxn];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        len=strlen(s);
        start=0;countt=0;mcount=0;
		mr=ml=0;
		for (int i = 0; i <= len; i++)
		{
			vis[i].l = -1;
			vis[i].co = 0;
		}
		vis[0].l = -1; vis[0].co = 0;
        for(int i=0;i<len;i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
				/*if (vis[st.size()].l == -1)
				{*/
					vis[st.size()].l = i;
					vis[st.size()].co = countt;
			/*	}*/
            }
            else if(s[i]==')')
            {
				if (!st.empty() && st.top() == '(')
				{
					st.pop();
					int num = st.size();

					if ((countt - vis[num].co) >= mcount)
					{
						if ((i - vis[num].l - 1) > (mr - ml))
						{
							mr = i;
							ml = vis[num].l + 1;
							mcount = countt - vis[num - 1].co;
						}
					}

					continue;
				}
				st.push(s[i]);
				vis[st.size()].l = i;
				vis[st.size()].co = countt;
			
            }
            else if(s[i]=='[')
            {
                st.push(s[i]);
				countt++;
				/*	if (vis[st.size()].l == -1)
					{*/
					vis[st.size()].l = i;
					vis[st.size()].co = countt;
				/*}*/          
            }
            else
            {
				if (!st.empty()&&st.top()=='[')
				{
					st.pop();
					int num = st.size();
					if ((countt-vis[num].co) >= mcount)
					{
						if ((i - vis[num].l-1) > (mr - ml))
						{
							mr = i;
							ml = vis[num].l+1;
							mcount = countt -vis[num].co;
						}
					}
					continue;
				}
				st.push(s[i]);
				vis[st.size()].l = i;
				vis[st.size()].co = countt;						
            }
        }
        if(mcount==0)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n",mcount);
            for(int i=ml;i<=mr;i++)
            {
                printf("%c",s[i]);
            }
            printf("\n");
        }
		while (!st.empty())
		{
			st.pop();
		}
    }

    return 0;
}
