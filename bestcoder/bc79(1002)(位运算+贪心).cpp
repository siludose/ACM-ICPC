#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
#include<cstdio>//g++的恶心点之一，单引用iostream不算数
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;
typedef __int64 dl;
int main()
{
    int t,i,flag;
    scanf("%d",&t);
    for(;t--;)
    {
        dl a,b,c,d,res=0;
        scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d);//dl就是I64
        for(i=61,flag=1;i>=0;i--)//从最高位进行，所以贪心
        {
            dl l=((dl)1<<i),r=l+l-1;//l是二进制为第i位为1的数，r是从0到i位都为1的数
            dl e=((~a)&l),f=(b&l),g=((~c)&l),h=(d&l);
            //e表示a的i位是否为0
            //f表示b的i位是否为1
            //g表示c的i位是否为0
            //h表示d的i位是否未1
            //a b绝对不可能是 1 0，不管是第1次还是之后的全被筛了
            if(e&&f&&g&&h)//这种情况表示               a b c d 
                //                               e=f=g 0 1 0 1 
                //        
                // ，从该位起后面的数字可以为1也可以为0，所以直接出结果
            {
                printf("%I64d\n",res^r);flag=0;
                break;
            }
            if(e==f)//                 0 1 0 0//这种情况因为第二区间全是0所以第一区间需要取1，所以a要这一位后面全部取0，其后同理
                    //                  0 1 1 1
            {
                if(e==g)a^=l,a&=l;
                else b^=l,b|=(l-1);
                res^=l;
            }
            else if(g==h)              
            {
                if(e==g)c^=l,c&=l;
                //                       0 0 0 1
                //                       1 1 1 0
                else d^=l,d|=(l-1);
                //                       1 1 0 1
                //                       0 0 1 0
                res^=l;
            }
            else
            {
                if(e!=g)res^=l;  //这种情况abcd是1 1 0 0
                //                               0 0 1 1这种情况可以使res加上这一位
                //所以res不加这一位的情况是1 1 1 1 或者0 0 0 0
            }    
        }
        if(flag)printf("%d\n",res);
    }
    return 0;
}