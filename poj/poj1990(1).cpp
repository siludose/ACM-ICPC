#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int64;
const int MAXN = 20010;

struct Node{
	int x;
	int v;
	bool operator<(const Node& s)const{
		return v < s.v; 
	}
};
Node node[MAXN];
int n;
int treeCount[MAXN];
int treeDis[MAXN];

int lowbit(int x){
	return x&(-x);
}

int64 getSum(int x , int *arr){
	int64 sum = 0;
	while(x){
		sum += arr[x];
		x -= lowbit(x);
	}
	return sum;
}

void add(int x , int val , int *arr){
	while(x < MAXN){
		arr[x] += val; 
		x += lowbit(x); 
	}
}

int64 solve(){
	int64 ans = 0;
	int64 totalDis = 0;
	memset(treeCount , 0 , sizeof(treeCount));
	memset(treeDis , 0 , sizeof(treeDis));
	sort(node , node+n);

	for(int i = 0 ; i < n ; i++){
		int64 count = getSum(node[i].x , treeCount); 
		int64 dis = getSum(node[i].x , treeDis);
		// left
		ans += node[i].v*(count*node[i].x-dis);
		// right
		ans += node[i].v*((totalDis-dis-(i-count)*node[i].x));
		// update 
		totalDis += node[i].x;
		add(node[i].x , 1 , treeCount);
		add(node[i].x , node[i].x , treeDis);
	}
	return ans;
}

int main(){
	freopen("input.txt","r",stdin);
	while(scanf("%d" , &n) != EOF){
		for(int i = 0 ; i < n ; i++) 
			scanf("%d%d" , &node[i].v , &node[i].x);
		printf("%lld\n" , solve());
	}
	return 0;
}