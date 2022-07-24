#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e3+100;
char a[maxn], b[maxn], path[maxn];
int dp[maxn][maxn];
int main(){
	scanf("%s%s", a+1, b+1);
	int n = strlen(a+1), m = strlen(b+1);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i]==b[j]) dp[i][j] = dp[i-1][j-1]+1; //有新的公共元素则考虑 
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); //否则考虑继承
		}
	}
//	printf("%d\n", dp[n][m]);
	int pos = dp[n][m];
	while(n&&m){
		if(a[n]==b[m]){
			path[pos--] = a[n];
			n--, m--;
		}
		else if(dp[n-1][m]>dp[n][m-1]) n--;
		else m--;
	}
	printf("%s", path+1);
}
