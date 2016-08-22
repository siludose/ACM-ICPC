#include<iostream>
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;
const int MAX = 2005;


int dp[MAX][MAX];
int add[30], del[30];



int main() {
	int n, m, i, j, len;
	char c, str[MAX];
	cin >> n >> m >> str;
	for (i = 0; i < n; i++) {
		cin >> c;
		cin >> add[c - 'a'] >> del[c - 'a'];
	}
	for (len = 1; len < m; len++)
		for (i = 0; i + len < m; i++) {
			j = i + len;
			if (str[i] == str[j]) {
				dp[i][j] = dp[i + 1][j - 1];
			}
			else {
				dp[i][j] = min(
					min(dp[i + 1][j] + add[str[i] - 'a'], dp[i][j - 1] + add[str[j] - 'a']),
					min(dp[i + 1][j] + del[str[i] - 'a'], dp[i][j - 1] + del[str[j] - 'a']));
			}
		}
	cout << dp[0][m - 1] << endl;
	return 0;
}
