#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include<algorithm>
using namespace std;
int main()
{
	string temp;
	set<string>ssss;
	set<string>ssss2;
	string s;
	stringstream ss;
	getline(cin,s);
	ss.clear();
	ss.str(s);
	while(ss>>temp)
	{
		ssss.insert(temp);
	}
	set<string>::iterator iter1=ssss.begin(); 
	set<string>::iterator iter2=ssss.begin();
	set<string>::iterator iter3=ssss.begin();
	set<string>::iterator iter4=ssss.begin();
	for(;iter1!=ssss.end();iter1++)
	{
		for(;iter2!=ssss.end();iter2++)
		{
			
		}
	}
	return 0;
}