#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<iostream>
#include<algorithm>
char p[100005], text[100005];
int next[100005];int num[1000005];
void makenext(const char P[], int next[])
{
    int q, k;
    int m = strlen(P);
    next[0] = 0;
    for (q = 1, k = 0;q < m;q++)
    {
        while (k > 0 && P[q] != P[k])
        {
            k = next[k - 1];
        }
        if (P[q] == P[k])
        {
            k++;
        }
        next[q] = k;
    }
}

int kmp(const char T[], const char P[], int next[])
{
    int n, m;
    int i, q;
    n = strlen(T);
    m = strlen(P);
    makenext(P, next);
    for (i = 0, q = 0;i < n;i++)
    {
        while (q > 0 && P[q] != T[i])
            q = next[q - 1];
        if (P[q] == T[i])
        {
            q++;
        }
        if (q == m)
        {
            return i - m + 1;
        }
    }
    return -1;
}
int main()
{
    int t;
    scanf("%d", &t);
    for (int t1 = 1;t1 <= t;t1++) {
        memset(next, 0, sizeof(next));
        memset(num, 0, sizeof(num));
        memset(p, 0, sizeof(p));
        memset(text, 0, sizeof(text));
        scanf("%s%s", text, p);
        makenext(p, next);
        int text_l = strlen(text), p_l = strlen(p);
        int off = 0;int n = 0;int ans = 0;
        while (-1 != (off = kmp(text + n, p, next + n))) {
            for (int i = 0;i < p_l;i++)
                num[i + n + off]++;
            n += off + 1;
        }

        for (int u = 0;u < text_l;u++) {
            if (num[u] == 0)
                continue;
            int times = 0;
            for (int i = u;i < text_l;i += p_l)
            {

                if (num[i] > 0 && i + p_l <= text_l)
                {
                    for (int o = 0;o < p_l;o++)
                        num[i + o]--;
                    times++;
                }
            }
            if (times != 0)
                ans += (int)pow(2, times) - 1;
            ans %= 1000000007;
        }
        printf("Case #%d: %d\n", t1, ans + 1);
    }
    return 0;
}