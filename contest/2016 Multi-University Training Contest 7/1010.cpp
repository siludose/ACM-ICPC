#pragma comment(linker, "/STACK:1024000000,1024000000") 
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<stack>
#include <stdlib.h>
#pragma warning(disable:4996)
using namespace std;
#define maxn 110000

int n;
char s1[20],s2[20];
struct ppp
{
	int num;
	int time;
}pp[maxn];
int index;

/***********************************************************************/
typedef int Type;

typedef struct _LeftistNode {
	Type   key;                    // �ؼ���(��ֵ)
	int npl;                    // ��·������(Null Path Length)
	struct _LeftistNode *left;    // ����
	struct _LeftistNode *right;    // �Һ���
}LeftistNode, *LeftistHeap;

/*
* ���������ڵ������
*/
static void swap_leftist_node(LeftistNode *x, LeftistNode *y)
{
	LeftistNode tmp = *x;
	*x = *y;
	*y = tmp;
}

/*
* ��ȡ��Сֵ
*
* ����ֵ��
*    �ɹ�����0��ʧ�ܷ���-1
*/
int leftist_minimum(LeftistHeap heap, int *pval)
{
	if (heap == NULL)
		return -1;

	*pval = heap->key;

	return 0;
}

/*
* �ϲ�"�����x"��"�����y"
*
* ����ֵ��
*     �ϲ��õ������ĸ��ڵ�
*/
LeftistNode* merge_leftist(LeftistHeap x, LeftistHeap y)
{
	if (x == NULL)
		return y;
	if (y == NULL)
		return x;

	// �ϲ�x��yʱ����x��Ϊ�ϲ�������ĸ���
	// ����Ĳ����Ǳ�֤: x��key < y��key
	if (x->key > y->key)
		swap_leftist_node(x, y);

	// ��x���Һ��Ӻ�y�ϲ���"�ϲ�������ĸ�"��x���Һ��ӡ�
	x->right = merge_leftist(x->right, y);

	// ���"x������Ϊ��" ���� "x�����ӵ�npl<�Һ��ӵ�npl"
	// �򣬽���x��y
	if (x->left == NULL || x->left->npl < x->right->npl)
	{
		LeftistNode *tmp = x->left;
		x->left = x->right;
		x->right = tmp;
	}
	// ���úϲ��������(x)��npl
	if (x->right == NULL || x->left == NULL)
		x->npl = 0;
	else
		x->npl = (x->left->npl > x->right->npl) ? (x->right->npl + 1) : (x->left->npl + 1);

	return x;
}

/*
* �½����(key)����������뵽�������
*
* ����˵����
*     heap ����ѵĸ����
*     key ������ļ�ֵ
* ����ֵ��
*     ���ڵ�
*/
LeftistNode* insert_leftist(LeftistHeap heap, Type key)
{
	LeftistNode *node;    // �½����

						  // ����½����ʧ�ܣ��򷵻ء�
	if ((node = (LeftistNode *)malloc(sizeof(LeftistNode))) == NULL)
		return heap;
	node->key = key;
	node->npl = 0;
	node->left = node->right = NULL;

	return merge_leftist(heap, node);
}

/*
* ȡ�����ڵ�
*
* ����ֵ��
*     ȡ�����ڵ��������ĸ��ڵ�
*/
LeftistNode* delete_leftist(LeftistHeap heap)
{
	if (heap == NULL)
		return NULL;

	LeftistNode *l = heap->left;
	LeftistNode *r = heap->right;

	// ɾ�����ڵ�
	free(heap);
	if (l == nullptr&&r == nullptr)
		return nullptr;
	return merge_leftist(l, r); // �������������ϲ��������
}

/*
* ���������
*/
void destroy_leftist(LeftistHeap heap)
{
	if (heap == NULL)
		return;

	if (heap->left != NULL)
		destroy_leftist(heap->left);
	if (heap->right != NULL)
		destroy_leftist(heap->right);

	free(heap);
}
/****************************************************************************************************/
int main()
{
    freopen("input.txt","r",stdin);
    int cas=0;
	while(scanf("%d",&n),n!=0)
    {
        printf("Case #%d:\n",++cas);
		index = 0;
		LeftistHeap a=NULL, b=NULL;
        for(int i=0;i<n;i++)
        {

            scanf("%s %s",s1,s2);
            if(s1[1]=='u')
            {
				index++;
                scanf("%d",&pp[index].num);
				pp[index].time = index;
				if (s2[0] == 'A')
				{
					a = insert_leftist(a,-index);
				}
				else if (s2[0] == 'B')
				{
					b = insert_leftist(b, -index);
				}
            }
            else if(s1[1]=='o')
            {
				if (s2[0] == 'A')
				{
					int cc;
					leftist_minimum(a, &cc);
					printf("%d\n", pp[-cc].num);
					if (a == b)
					{
						a = delete_leftist(a);
						b = a;
					}
					else {
						a = delete_leftist(a);
					}
				}
				else if (s2[0] == 'B')
				{
					int cc;
					leftist_minimum(b, &cc);
					printf("%d\n", pp[-cc].num);
					if (a == b)
					{
						a = delete_leftist(a);
						b = a;
					}
					else {
						b = delete_leftist(b);
					}
				}
            }
            else
            {
				scanf("%s", s2);
				if (s2[0] == 'A')
				{				
					b = merge_leftist(a, b);
				}
				else if (s2[0] == 'B')
				{
					a = merge_leftist(a, b);
				}
            }
        }
		if (a == b) {
			destroy_leftist(a);
		}
		else
		{
			destroy_leftist(a); destroy_leftist(b);
		}
    }
    return 0;
}
