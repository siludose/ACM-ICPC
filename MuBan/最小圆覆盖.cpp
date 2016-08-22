/*
�����㼯���е����СԲ���㷨
ƽ������n���㣬����n��������꣬����һ���뾶��С��Բ����n����ȫ����Χ���������Բ�ϡ�

1. �ڵ㼯����ȡ3��A,B,C��
2. ��һ������A,B,C�������СԲ,Բ�ܿ���ͨ����3�㣬Ҳ����ֻͨ����������,��������3��.��һ�����Բ���ϵ�����һ����λ��Բ��һ��ֱ�������ˡ�
3. �ڵ㼯���ҳ������2������ԲԲ����Զ��D�㣬��D������Բ�ڻ�Բ���ϣ����Բ��Ϊ�����Բ���㷨����.��ִ�е�4����
4. ��A,B,C,D��ѡ3����,ʹ���������ɵ�һ��������4�����ԲΪ��С����3���Ϊ�µ�A,B,C������ִ�е�2�������ڵ�4�����ɵ�Բ��Բ��ֻͨ��A,B,C,D�е����㣬��Բ���ϵ�����ȡ���µ�A��B,������������ȡһ����Ϊ�µ�C��

*/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define N 110
struct POINT {
    double x, y;
} p[N];
int n;
inline double dist(const POINT &a, const POINT &b) {
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
POINT circumcenter(POINT &a, POINT &b, POINT &c) {
    POINT ret;
    double a1=b.x-a.x, b1=b.y-a.y, c1=(a1*a1+b1*b1)/2;
    double a2=c.x-a.x, b2=c.y-a.y, c2=(a2*a2+b2*b2)/2;
    double d = a1*b2 - a2*b1;
    ret.x = a.x + (c1*b2-c2*b1)/d;
    ret.y = a.y + (a1*c2-a2*c1)/d;
    return ret;
}
void solve() {
    random_shuffle(p, p+n);  //��������У�std������������
    POINT c;
    double r = 0;
    for (int i=1; i<n; i++) {
        if (dist(p[i], c) <= r) continue;
        c = p[i];
        r = 0;
        for (int j=0; j<i; j++) {
            if (dist(p[j], c) <= r) continue;
            c.x = (p[i].x+p[j].x)/2;
            c.y = (p[i].y+p[j].y)/2;
            r = dist(p[j], c);
            for (int k=0; k<j; k++) {
                if (dist(p[k], c) <= r) continue;
                c = circumcenter(p[i], p[j], p[k]);
                r = dist(p[i], c);
            }
        }
    }
    printf("%.2lf %.2lf %.2lf\n", c.x, c.y, r);
}
int main() {
    while (scanf(" %d", &n) == 1 && n) {
        for (int i=0; i<n; i++)
            scanf(" %lf %lf", &p[i].x, &p[i].y);
        solve();
    }
    return 0;
}