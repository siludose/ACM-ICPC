/*
���ǺϷ�������ˮ�� 
��Ӧ�ñ�λ�������ţ�����ת��Ϊ�򵥵Ĺ�����Ŀ��
���Ƚ�d++��Ȼ��ʼʵʱ�����������Ϊ1�ĸ���
���������sumС��s1���Ǿ�����С��Ϊ0��λ����Ϊ3
���sum����s2���Ǿ�����С��Ϊ1��λ�ü�1����ȡǰһλҲΪ1������sum�ĸ���
�����ϲ����γ�ѭ�� 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cmath>
//#pragma warning(disable:4996)
using namespace std;
#define maxn 50
#define ll long long
ll d;
int s1,s2,t;
bool D[maxn];
int main()
{
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        memset(D,0,sizeof(D));
        scanf("%I64d",&d);
        scanf("%d%d",&s1,&s2);
        d++;int sum=0;
        for(int i=0;i<=31;i++)
            if(d&((ll)1<<i))
                {D[i]=true;sum++;}
        while(1)
        {
            if(sum>=s1&&sum<=s2)
            {
                printf("Case #%d: %I64d\n",cas,d);
                break;
            }
            if(sum<s1)
            {
                int x=0;
                while(D[x]!=false)
                    x++;
                D[x]=true;
                d^=(ll)1<<x;
                sum++;
            }
            else if(sum>s2)
            {
                int x=0;
                while(D[x]==false)
                    x++;
                d+=(ll)1<<x;
                memset(D,0,sizeof(D));sum=0;
                for(int i=0;i<=31;i++)
                    if(d&((ll)1<<i))
                        {D[i]=true;sum++;}
            }
        }
    }
    return 0;
}
