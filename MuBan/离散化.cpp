#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N=100;
int n;
vector<pair<int,int>> zone;
vector<int> abc;
int main()
{
    freopen("input.txt","r",stdin);
    cin>>n;
    int a,b;
    for (int i=0;i<n;i++)
    {
        cin>>a>>b;
        zone.push_back(make_pair(a,b));
    }
    for (int i=0;i<n;i++)
    {
        abc.push_back(zone[i].first);
        abc.push_back(zone[i].second);
    }
    sort(abc.begin(),abc.end());
    vector<int>::iterator iter = unique(abc.begin(),abc.end());
    abc.erase(iter,abc.end());
    iter=abc.begin();
    for (int i=0;i<n;i++)
    {
        zone[i].first=lower_bound(abc.begin(),abc.end(),zone[i].first)-abc.begin();
        zone[i].second=lower_bound(abc.begin(),abc.end(),zone[i].second)-abc.begin();
    }
    return 0;
}