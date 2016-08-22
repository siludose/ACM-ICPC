#include <iostream>
#include <string.h>
#include<stdlib.h>
#include <cmath>
#pragma warning(disable:4996)
using namespace std;
const int maxn = 4000 + 24;
int a[maxn], b[maxn], c[maxn], d[maxn];
int n;
struct node
{
	int num;
	struct node *next;
};
struct hashlist
{
	struct node *head;
}list1[1000000];
int hashing(int num)
{
	return num % 10000;
}
void hashlist_insect(int key,int num)
{
	if (list1[key].head == NULL)
	{
		struct node *p = (struct node *)malloc(sizeof(struct node));
		p->num = num;
		p->next = NULL;
		list1[key].head= p;
		return;
	}
	struct node *cur = list1[key].head;
	while (cur->next!=NULL)
	{
		cur = cur->next;
	}
	struct node *p = (struct node *)malloc(sizeof(struct node));
	p->num = num;
	cur->next = p;
}
int hashlist_search(int key,int num)
{
	int res = 0;
	struct node *cur = list1[key].head;
	while (cur!=NULL)
	{
		if (cur->num==(-num))
		{
			res++;
		}
		cur=cur->next;
	}
	return res;
}
int main()
{
	freopen("input.txt", "r", stdin);
	int case1;
	scanf("%d",&case1);
	while (case1--)
	{
		int res = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int a_add_b = a[i] + b[j];
				hashlist_insect(hashing(abs(a_add_b)), a_add_b);
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int c_add_d = c[i] + d[j];
				res += hashlist_search(hashing(abs(c_add_d)), c_add_d);
			}
		}
		cout << res;

	}
	
	return 0;
}