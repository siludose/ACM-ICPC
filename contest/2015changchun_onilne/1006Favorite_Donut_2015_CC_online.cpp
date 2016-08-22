#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cstring>
//#pragma warning(disable:4996)
using namespace std;
int t,n;
#define maxn 21000
char s1[maxn*2];
char s2[maxn*2];

int ans;
int get_mstring(char *s)//最大表示法
{
    int len = strlen(s);
    int i = 0, j = 1, k = 0;
    while (i<len&&j<len&&k<len)
    {
        int t = s[(i + k) % len] - s[(j + k) % len];
        if (t == 0)
            k++;
        else
        {
            if (t>0)
                j += k + 1;
            else i += k + 1;
            if (i == j) j++;
            k = 0;
        }
    }
    return min(i, j);
}
char a[maxn*2], b[maxn*2];
int Next[maxn];
char now1[maxn], now2[maxn];
void getNext(char s[], int len)
{
    int i, j;
    i = 0; j = -1;
    Next[0] = -1;
    while (i < len)
    {
        if (j == -1 || s[i] == s[j])
            ++i, ++j, Next[i] = j;
        else
            j = Next[j];
    }
}
int KMP(const char a[], const char b[], int pos, int next[], int la, int lb)
{
    int i, j;
    i = pos, j = 0;
    next[0] = -1;
    while (i < la)
    {
        if (j == -1 || a[i] == b[j])
            ++i, ++j;
        else
            j = next[j];
        if (j >= lb)
        {
            if (i<2 * n)  //这边不能 有 -1  
            {
                ans = min(ans, n - (i + 1 - n) + 1);
            }
            j = next[j]; //如果不能子链重合 这边要改成j=0;  
        }
    }
    return ans;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        scanf("%s", s1);
        for (int i = 0; i < n; i++)
            s2[i] = s1[n - i - 1];
        s2[n] = '\0';

        int l0 = get_mstring(s1);
        for (int i = 0; i < n; i++)
            now1[i] = s1[(i + l0) % n];
        now1[n] = '\0';

        for (int i = 0; i < n; i++)
            a[i] = a[n + i] = s2[i];
        a[n * 2] = '\0';

        int l2 = get_mstring(s2);
        for (int i = 0; i < n; i++)
            now2[i] = s2[(i + l2) % n];
        now2[n] = '\0';


        l0++;
        l2 = ans = n - (l2 + 1) + 1;

        int dx = strcmp(now1, now2);
        if (dx < 0)
        {
            getNext(now2, n);
            KMP(a, now2, 0, Next, 2 * n, n);

            printf("%d 1\n", ans);
        }
        else if (dx>0)
        {
            printf("%d 0\n", l0);
        }
        else
        {
            getNext(now2, n);
            KMP(a, now2, 0, Next, 2 * n, n);

            if (ans < l0)
                printf("%d 1\n", ans);
            else
                printf("%d 0\n", l0);
        }    
    }
    return 0;
}