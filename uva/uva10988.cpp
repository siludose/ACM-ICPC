#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

char s[101000];
int Next[101000];

int main()
{
  int cur,last;//cur为光标位置，last为显示屏最后一个字符
  while(~scanf("%s",s+1))
  {
    memset(Next,0,sizeof(Next));
    int len = strlen(s+1);
    Next[0] = 0;
    cur = last = 0;
    for(int i = 1; i <= len; i++)
    {
      if(s[i] == '[')
        cur = 0;
      else if(s[i] == ']')
        cur = last;
      else
      {
        //模拟插入链表过程
        Next[i] = Next[cur];//第i个字符指向光标位置
        Next[cur] = i;//光标指向下一个字符
        if(cur == last)//只有光标在当前最后一个字符位置或是遇到]后才执行
          last = i;
        cur = i;//移动光标
      }
    }
    for(int i = Next[0]; i != 0; i = Next[i])
      printf("%c",s[i]);
    printf("\n");
    memset(s,0,sizeof(s));
  }

  return 0;
}