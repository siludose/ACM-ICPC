/*
该题的重点在排序
bool operator<(const COW &b)const  
    { return st<b.st||(st==b.st&&ed>b.ed); }  

*/
#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <vector>  
#include <map>  
#include <algorithm>  
using namespace std;  
  
#define LL(x) (x<<1)  
#define RR(x) (x<<1|1)  
#define MID(a,b) (a+((b-a)>>1))  
const int N=1e5+5;  
  
struct COW  
{  
    int st,ed,id;  
    COW(){}  
    COW(int a,int b,int c){st=a;ed=b;id=c;}  
    bool operator<(const COW &b)const  
    { return st<b.st||(st==b.st&&ed>b.ed); }  
}cow[N];  
struct node  
{  
    int lft,rht,sum;  
    int mid(){return MID(lft,rht);}  
};  
  
int res[N],n;  
  
struct Segtree  
{  
    node tree[N*4];  
    void build(int lft,int rht,int ind)  
    {  
        tree[ind].lft=lft;  tree[ind].rht=rht;  
        tree[ind].sum=0;  
        if(lft!=rht)  
        {  
            int mid=tree[ind].mid();  
            build(lft,mid,LL(ind));  
            build(mid+1,rht,RR(ind));  
        }  
    }  
    void updata(int pos,int ind)  
    {  
        tree[ind].sum++;  
        if(tree[ind].lft==tree[ind].rht) return;  
        else   
        {  
            int mid=tree[ind].mid();  
            if(pos<=mid) updata(pos,LL(ind));  
            else updata(pos,RR(ind));  
        }  
    }  
    int query(int st,int ed,int ind)  
    {  
        int lft=tree[ind].lft,rht=tree[ind].rht;  
        if(st<=lft&&rht<=ed) return tree[ind].sum;  
        else   
        {  
            int mid=tree[ind].mid(),sum=0;  
            if(st<=mid) sum+=query(st,ed,LL(ind));  
            if(ed> mid) sum+=query(st,ed,RR(ind));  
            return sum;  
        }  
    }  
}seg;  
int main()  
{  
    while(scanf("%d",&n)&&n)  
    {  
        for(int i=0;i<n;i++)  
        {  
            int a,b;  
            scanf("%d%d",&a,&b);  
            cow[i]=COW(a,b,i);  
        }  
        sort(cow,cow+n);  
        seg.build(0,N,1);  
        for(int i=0;i<n;i++)  
        {  
            if(i!=0&&cow[i].st==cow[i-1].st&&cow[i].ed==cow[i-1].ed)  
                res[cow[i].id]=res[cow[i-1].id];  
            else res[cow[i].id]=seg.query(cow[i].ed,N,1);  
            seg.updata(cow[i].ed,1);  
        }  
        for(int i=0;i<n;i++) printf("%d%c",res[i],i==n-1?'\n':' ');  
    }  
    return 0;  
} 