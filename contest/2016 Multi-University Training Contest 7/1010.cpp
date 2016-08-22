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
	Type   key;                    // 关键字(键值)
	int npl;                    // 零路经长度(Null Path Length)
	struct _LeftistNode *left;    // 左孩子
	struct _LeftistNode *right;    // 右孩子
}LeftistNode, *LeftistHeap;

/*
* 交换两个节点的内容
*/
static void swap_leftist_node(LeftistNode *x, LeftistNode *y)
{
	LeftistNode tmp = *x;
	*x = *y;
	*y = tmp;
}

/*
* 获取最小值
*
* 返回值：
*    成功返回0，失败返回-1
*/
int leftist_minimum(LeftistHeap heap, int *pval)
{
	if (heap == NULL)
		return -1;

	*pval = heap->key;

	return 0;
}

/*
* 合并"左倾堆x"和"左倾堆y"
*
* 返回值：
*     合并得到的树的根节点
*/
LeftistNode* merge_leftist(LeftistHeap x, LeftistHeap y)
{
	if (x == NULL)
		return y;
	if (y == NULL)
		return x;

	// 合并x和y时，将x作为合并后的树的根；
	// 这里的操作是保证: x的key < y的key
	if (x->key > y->key)
		swap_leftist_node(x, y);

	// 将x的右孩子和y合并，"合并后的树的根"是x的右孩子。
	x->right = merge_leftist(x->right, y);

	// 如果"x的左孩子为空" 或者 "x的左孩子的npl<右孩子的npl"
	// 则，交换x和y
	if (x->left == NULL || x->left->npl < x->right->npl)
	{
		LeftistNode *tmp = x->left;
		x->left = x->right;
		x->right = tmp;
	}
	// 设置合并后的新树(x)的npl
	if (x->right == NULL || x->left == NULL)
		x->npl = 0;
	else
		x->npl = (x->left->npl > x->right->npl) ? (x->right->npl + 1) : (x->left->npl + 1);

	return x;
}

/*
* 新建结点(key)，并将其插入到左倾堆中
*
* 参数说明：
*     heap 左倾堆的根结点
*     key 插入结点的键值
* 返回值：
*     根节点
*/
LeftistNode* insert_leftist(LeftistHeap heap, Type key)
{
	LeftistNode *node;    // 新建结点

						  // 如果新建结点失败，则返回。
	if ((node = (LeftistNode *)malloc(sizeof(LeftistNode))) == NULL)
		return heap;
	node->key = key;
	node->npl = 0;
	node->left = node->right = NULL;

	return merge_leftist(heap, node);
}

/*
* 取出根节点
*
* 返回值：
*     取出根节点后的新树的根节点
*/
LeftistNode* delete_leftist(LeftistHeap heap)
{
	if (heap == NULL)
		return NULL;

	LeftistNode *l = heap->left;
	LeftistNode *r = heap->right;

	// 删除根节点
	free(heap);
	if (l == nullptr&&r == nullptr)
		return nullptr;
	return merge_leftist(l, r); // 返回左右子树合并后的新树
}

/*
* 销毁左倾堆
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
