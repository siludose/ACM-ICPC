/*
包含点集所有点的最小圆的算法
平面上有n个点，给定n个点的坐标，试找一个半径最小的圆，将n个点全部包围，点可以在圆上。

1. 在点集中任取3点A,B,C。
2. 作一个包含A,B,C三点的最小圆,圆周可能通过这3点，也可能只通过其中两点,但包含第3点.后一种情况圆周上的两点一定是位于圆的一条直径的两端。
3. 在点集中找出距离第2步所建圆圆心最远的D点，若D点已在圆内或圆周上，则该圆即为所求的圆，算法结束.则，执行第4步。
4. 在A,B,C,D中选3个点,使由它们生成的一个包含这4个点的圆为最小，这3点成为新的A,B,C，返回执行第2步。若在第4步生成的圆的圆周只通过A,B,C,D中的两点，则圆周上的两点取成新的A和B,从另两点中任取一点作为新的C。

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
    random_shuffle(p, p+n);  //随机化序列，std里面的随机函数
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