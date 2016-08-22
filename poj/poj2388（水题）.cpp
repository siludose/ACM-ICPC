#include<iostream>
#include<algorithm>
using namespace std;
#define N 10010
__int64 a[N];
int n;
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
    }
    sort(a,a+n);
    printf("%I64d",a[n/2]);
    return 0;
}
