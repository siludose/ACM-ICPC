#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
using namespace std;
#define mx 100010
int Min[mx][20],Max[mx][20],n,m,a[mx];

void makermq(){
	for (int i = 1;i <= n;i ++) 
		Min[i][0] = Max[i][0] = i;

	for (int i = 1;(1 << i) <= n;i ++){
		for(int j = 1;j + (1 << i) - 1 <= n;j ++){
			int p = Min[j][i - 1],q = Min[j + (1 << i - 1)][i - 1];
			if (a[p] < a[q] || (a[p] == a[q] && p < q)) 
				Min[j][i] = p;
			else
				Min[j][i] = q;
			p = Max[j][i - 1],q = Max[j + (1 << i - 1)][i - 1];
			if (a[p] > a[q] || (a[p] == a[q] && p < q)) 
				Max[j][i] = p;
			else 
				Max[j][i] = q;
		}
	}
}

int ask(int l,int r,int q){
	int tmp = (int)log(   double(r - l + 1) )/ log(2.0);
	int k1,k2;

	if (q == 0){
		k1 = Min[l][tmp],k2 = Min[r - (1 << tmp) + 1][tmp];
		if (a[k1] < a[k2] || (a[k1] == a[k2] && k1 < k2)) return k1;
		else return k2;
	}
	else{
		k1 = Max[l][tmp],k2 = Max[r - (1 << tmp) + 1][tmp];
		if (a[k1] > a[k2] || (a[k1] == a[k2] && k1 < k2)) return k1;
		else return k2;
	}
}

int main(){   
	freopen("input.txt","r",stdin);
	cin >> n >> m;
	for (int i = 1;i <= n;i ++) cin >> a[i];

	makermq();

	int l,r,q;
	for (int i = 1;i <= m;i ++){
		cin >> l >> r >> q;
		cout << ask(l,r,q) << endl;
	}
}