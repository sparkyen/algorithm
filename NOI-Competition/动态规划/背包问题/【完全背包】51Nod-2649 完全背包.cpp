/*
完全背包+滚动数组优化 
*/ 
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 5e4+100;
int n, m, w[maxn], v[maxn];
int f[200][maxn], dp[maxn]; 
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &w[i], &v[i]);
	//solution 1: TLE
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= m; j++)
			for(int k = 0; k*w[i] <= j; k++)
				f[i][j] = max(f[i][j], f[i-1][j-k*w[i]]+k*v[i]);
	//solution 2: AC_78ms
//	for(int i = 1; i <= n; i++)
//		for(int j = 0; j <= m; j++){
//			f[i][j] = f[i-1][j];
//			if(j>=w[i]) f[i][j] = max(f[i][j], f[i][j-w[i]]+v[i]);
//		}
	printf("%d", f[n][m]);
	//solution 3: AC_31ms
//	for(int i = 1; i <= n; i++){
//		for(int j = w[i]; j <= m; j++){
//			dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
//		}
//	} 
//	printf("%d", dp[m]);
			
	
}
/*
测试样例 
2 11
2 3
6 14
*/

