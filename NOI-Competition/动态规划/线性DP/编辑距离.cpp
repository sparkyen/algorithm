#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e3+100;
char a[maxn], b[maxn];
int dp[maxn][maxn];
int main(){
	scanf("%s%s", a+1, b+1);
	int n = strlen(a+1), m = strlen(b+1);
	for(int i = 1; i <= n; i++) dp[i][0] = i;
	for(int i = 1; i <= m; i++) dp[0][i] = i;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1];
			else dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1; 
//			cout << dp[i][j] << " ";
		}
//		cout << endl;
	}
	printf("%d", dp[n][m]);
}
