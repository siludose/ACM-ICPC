#include<iostream>
#include<cstdio>
#include<string.h>
#include<cstring>
#include<stdlib.h>
#pragma warning(disable:4996)
using namespace std;
#define maxn 100100
int t;
char x;
char s[maxn];
int q[maxn];
int countt;
struct trie /*????????*/
{
	int count;/*??????????*/
	trie *next[26];/*?????26???(??),?'a'-'z'*/
};

trie *root;

trie* newtrie()/*???????(???????????,??????????)*/
{
	trie *t;
	t = (trie*)malloc(sizeof(struct trie));
	memset(t, 0, sizeof(struct trie));
	return t;
}

void insert(char *ch) /*????,????????????  */
{
	int i;
	trie *t, *s;
	s = root;
	for (i = 0; ch[i]; i++)
	{
		if (s->next[ch[i] - 'a'])
		{
			s = s->next[ch[i] - 'a'];
			s->count = s->count + 1;
		}
		else
		{
			t = newtrie();
			s->next[ch[i] - 'a'] = t;
			s = t;
			s->count = 1;
		}
	}
}

int Search(char *ch)/*????,??0?????????????,???? */
{
	int i;
	trie *s = root;
	if (ch[0] == 0) return 0;
	for (i = 0; ch[i]; i++)
	{
		if (s->next[ch[i] - 'a'])
			s = s->next[ch[i] - 'a'];
		else
			break;
	}
	if (ch[i] == 0) return s->count;
	else return 0;
}

void del(trie *cur)
{
	for (int i = 0; i < 26; i++)
	{
		if (cur->next[i] != NULL)
			del(cur->next[i]);
	}
	free(cur);
}
int main()
{
	//freopen("input.txt", "r", stdin);
    scanf("%d",&t);
    countt=0;
    while(t--)
    {
		
		//getchar();
		scanf(" %c ", &x); 
        scanf("%s",s);
        int len=strlen(s);
        int num=0,i;
        for(i=0;i<len;i++)
        {
            if(x==s[i])
            {
                q[num++]=i;
            }
        }
		if(num==len)
		{
			printf("Case #%d: %d\n",++countt,num);continue;
		}
        char temp[maxn];
        int sum=0;
        for(i=2;i<len;i++)
        {
			root = newtrie();
            for(int j=0;j<num;j++)
            {
                if(q[j]+1>i)
                {
                    for(int k=q[j]+1-i;k<=q[j]&&q[j]+i<len;k++)
                    {
						strncpy(temp, s + k, i);
						temp[i] = '\0';
                        if(Search(temp)==0)
                        {
							insert(temp);
                            sum++;
                        }
                    }
                }
				else
				{
					for (int k = 0; k <= q[j] && k + i -1< len; k++)
					{
						strncpy(temp, s + k, i);
						temp[i] = '\0';
						if (Search(temp) == 0)
						{
							insert(temp);
							sum++;
						}
					}
				}
            }
			del(root);
        }
        printf("Case #%d: %d\n",++countt,sum+2);
    }
    return 0;
}
