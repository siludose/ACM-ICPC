#include<iostream>
#include<iostream>
#include<cstdio>
#include<string.h>
#include<stack>
using namespace std;
#define maxn 1000010
int t,len;
char s[maxn];
typedef struct 
{
    int l;
    char v;
	int you;
	int co;
}P;
struct Ans
{
    int l;
    int r;
    int co;
}ans;
struct Last
{
	int l;
	int r;
	int co;
	bool button;
}last;
stack<P> st;
void setans(P temp)
{
	if (temp.v == '[')
		temp.co--;
    if(ans.co== temp.co)
    {
        if((ans.r-ans.l)<(temp.you- temp.l-1))
        {
            ans.co= temp.co;
            ans.l= temp.l+1;
            ans.r= temp.you;
        }
    }
	if (ans.co < temp.co)
	{
		ans.co = temp.co;
		ans.l = temp.l+1;
		ans.r = temp.you;
	}

}
void setans2(P temp)
{
	if (ans.co == temp.co)
	{
		if ((ans.r - ans.l) < (temp.you - temp.l - 1))
		{
			ans.co = temp.co;
			ans.l = temp.l;
			ans.r = temp.you;
		}
	}
	if (ans.co < temp.co)
	{
		ans.co = temp.co;
		ans.l = temp.l;
		ans.r = temp.you;

	}
}
void init()
{
	ans.co = 0; ans.l = 0; ans.r = 0;
	while (!st.empty())
	{
		st.pop();
	}
	last.button = false;
}
int main()
{
	freopen("data01.in","r",stdin);
	freopen("output.txt","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
		init();
        scanf("%s",s);
        len=strlen(s);
		for (int i = 0; i < len; i++)
		{
			if (i==30421)
			{
				getchar();
			}
			switch (s[i])
			{
				case '(':
				{
					P temp;
					temp.l = i;
					temp.v = '(';
					temp.you = i;
					temp.co = 0;
					st.push(temp);
					break;
				}
				case ')':
				{
					if (st.empty())
					{
						last.button = false;
						continue;
					}
					if (st.top().v == '(')
					{
						P temp = st.top();
						st.pop();
						if (!st.empty())
						{
							st.top().you = i;
							st.top().co += temp.co;
							setans(st.top());
						}
						else
						{
							if (last.button)
							{
								if (temp.l - 1 == last.r)
								{
									temp.l = last.l;
									temp.co += last.co;
								}
							}
							temp.you = i;
							setans2(temp);
							last.l = temp.l;
							last.r = temp.you;
							last.co = temp.co;
							last.button = true;
						}
					}
					else
					{
						while (!st.empty())
						{
							st.pop();
						}
						last.button = false;
					}

					break;
				}
				case '[':
				{
					P temp;
					temp.l = i;
					temp.v = '[';
					temp.co = 1;
					temp.you = 0;
					st.push(temp);
					break;
				}
				case ']':
				{
					if (st.empty())
					{
						last.button = false;
						continue;
					}
					if (st.top().v == '[')
					{
						P temp = st.top();
						st.pop();
						if (!st.empty())
						{
							st.top().you = i;
							st.top().co += temp.co;
							setans(st.top());
						}
						else
						{
							if (last.button)
							{
								if (temp.l - 1 == last.r)
								{
									temp.l = last.l;
									temp.co += last.co;
								}
							}
							temp.you = i;
							setans2(temp);
							last.l = temp.l;
							last.r = temp.you;
							last.co = temp.co;
							last.button = true;
						}
					}
					else
					{
						while (!st.empty())
						{
							st.pop();
						}
						last.button = false;
					}
					break;
				}
			}
		}
		if (ans.co == 0)
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n", ans.co);
			for (int i = ans.l; i <= ans.r; i++)
			{
				printf("%c", s[i]);
			}
			printf("\n");
		}
    }

    return 0;
}
