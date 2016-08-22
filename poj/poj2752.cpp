#include <iostream>
#include <cstring>
using namespace std;
char a[] = "OURSTRONGXSEARCH";
char b[] = "SEARCH";
int occ[150];
int sizea = strlen(a);
int sizeb = strlen(b);
void sundayinitocc()
{
	int j;
	char a;
	for (a = 65; a <= 122;a++)	
		occ[a] = -1;
	for (j = 0; j < sizeb;j++)
		occ[b[j]] = j;
}
int sundaysearch()
{
	int i = 0, j = 0;
	while (i<sizea)
	{
		if (a[i]==b[j])
		{
			i++; j++;
		}
		else
		{
			j = occ[a[i + 1]];

		}
	}

}
int main()
{
	
	return 0;
}