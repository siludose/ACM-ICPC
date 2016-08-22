#include<iostream>
#include<string>
#include<cstring>
#include<malloc.h>
//#pragma warning(disable:4996)
using namespace std;
#define MAX 26
#define large 500000
typedef struct Tire
{
    Tire *next[MAX];
    int id;
    bool flag;
}Tire;
Tire *root=(Tire *)malloc(sizeof(Tire));
int color;
int degree[large+1];
int pre[large+1];
int creat(char *str)
{
    int len=strlen(str);
    Tire *p=root,*q;
    bool button=false;
    for(int i=0;i<len;i++)
    {
        int rt=str[i]-'a';
        if(p->next[rt]==NULL)
        {
            button=true;
            q=(Tire *)malloc(sizeof(Tire));
            for(int j=0;j<MAX;j++)
                q->next[j]=NULL;
            p->next[rt]=q;
            p=p->next[rt];
        }
        else
        {
            p=p->next[rt];
        }
    }
    if(button)
    {
        p->id=++color;
        p->flag=true;
    } 
    return p->id;
}
int find(int x)
{
    if(pre[x]!=x)
    {
        pre[x]=find(pre[x]);
    }
    return pre[x];
}
void union_set(int a,int b)
{
    int pa=find(a);
    int pb=find(b);
    pre[pb]=pa;
    return ;
}
int main()
{
    //freopen("input.txt","r",stdin);
    color=0;
    for(int k=1;k<=large;k++)
    {
        pre[k]=k;
    }
	for (int i = 0; i < MAX; i++)
	{
		root->next[i] = NULL;
	}
    char a[11],b[11];
    while(cin>>a>>b)
    {
        int i=creat(a);
        int j=creat(b);

        degree[i]++;
        degree[j]++;

        union_set(i,j);
    }

    int s=find(1);
    int num=0;
    for(int i=1;i<=color;i++)
    {
        if(degree[i]%2==1)
            num++;
        if(num>2)
        {
            cout<<"Impossible"<<endl;
            return 0;
        }
        if(find(i)!=s)
        {
            cout<<"Impossible"<<endl;
            return 0;
        }
    }
    if(num==1)
        cout<<"Impossible"<<endl;
    else
        cout<<"Possible"<<endl;
    return 0;
}
