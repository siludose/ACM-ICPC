#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#define maxn 50
using namespace std;
map<string,int>mp;
int t,countt;
char s[maxn];
char temp;
int main()
{
	countt=0;
	mp.insert(pair<string,int>("Cleveland Cavaliers",1));
	mp.insert(pair<string,int>("Golden State Warriors",2));
	mp.insert(pair<string,int>("San Antonio Spurs",5));
	mp.insert(pair<string,int>("Miami Heat",3));
	mp.insert(pair<string,int>("Dallas Mavericks",1));
	mp.insert(pair<string,int>("L.A. Lakers",11));
	mp.insert(pair<string,int>("Boston Celtics",17));
	mp.insert(pair<string,int>("Detroit Pistons",3));
	mp.insert(pair<string,int>("Chicago Bulls",6));
	mp.insert(pair<string,int>("Houston Rockets",2));
	mp.insert(pair<string,int>("Philadelphia 76ers",2));
	mp.insert(pair<string,int>("Seattle Sonics",1));
	mp.insert(pair<string,int>("Washington Bullets",1));
	mp.insert(pair<string,int>("Portland Trail Blazers",1));
	mp.insert(pair<string,int>("New York Knicks",2));
	mp.insert(pair<string,int>("Milwaukee Bucks",1));
	mp.insert(pair<string,int>("St. Louis Hawks",1));
	mp.insert(pair<string,int>("Syracuse Nats",1));	
	mp.insert(pair<string,int>("Baltimore Bullets",1));
	mp.insert(pair<string,int>("Minneapolis Lakers",5));
	mp.insert(pair<string,int>("Philadelphia Warriors",2));
	mp.insert(pair<string,int>("Rochester Royals",1));
	scanf("%d", &t); getchar();
    while(t--)
    {
		gets(s);
        map<string,int>::iterator it;
        it=mp.find(s);
        if(it!=mp.end())
            printf("Case #%d: %d\n",++countt,mp[s]);
        else
            printf("Case #%d: %d\n",++countt,0);
    }
    return 0;
}
