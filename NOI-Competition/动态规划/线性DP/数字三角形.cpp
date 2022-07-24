#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e3+100;
int n, a[maxn][maxn]; 
int dp[maxn][maxn], res;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			scanf("%d", &a[i][j]);
			dp[i][j] = a[i][j]+max(dp[i-1][j-1], dp[i-1][j]);
			if(i==n) res = max(res, dp[i][j]);
		}
	} 
	printf("%d", res);
}
