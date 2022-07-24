/*
01背包+路径打印 
*/ 
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e3+100;
int n, m, w[maxn];
int f[maxn][maxn], res[maxn];
int dp[maxn], path[maxn][maxn];
void solve1(){
	for(int i = 1; i <= n; i++){
		scanf("%d", &w[i]);
		for(int j = 0; j <= m; j++){
			f[i][j] = (i==1?0:f[i-1][j]);
			if(j>=w[i]) f[i][j] = max(f[i][j], f[i-1][j-w[i]]+w[i]);
		}
	}
	int c = m, id = 1;
	for(int i = n; i >= 1; i--){
		if(f[i][c]==f[i-1][c-w[i]]+w[i]) {
			res[id++] = w[i];
			c -= w[i];
		}
	}
	for(int i = id-1; i >= 1; i--) printf("%d ", res[i]); 
	printf("sum:%d\n", f[n][m]);
} 
void solve2(){
	//初始化 
	memset(dp, 0, sizeof(dp));
	memset(path, 0, sizeof(path));
	for(int i = 1; i <= n; i++) scanf("%d", &w[i]);
	for(int i = n; i >= 1; i--)
		for(int j = m; j >= w[i]; j--){
			/*
			对于测试样例 45 8 4 10 44 43 12 9 8 2
			取>=的结果：4 10 12 9 8 2 sum:45
			取>的结果：43 2 sum:45
			*/ 
			if(dp[j-w[i]]+w[i]>=dp[j]){
				dp[j] = dp[j-w[i]]+w[i];
				path[i][j] = 1;
			}
		}
	int j = m;
	for(int i = 1; i <= n; i++){
		if(path[i][j]==1){
			cout << w[i] << " ";
			j -= w[i];
		}
	}
	cout << "sum:" << dp[m] << endl;
}
int main(){
	while(~scanf("%d%d", &m, &n)){
//		solve1();
		solve2();
	}
}
/*
测试样例1： 
5 3 1 3 4
10 4 9 8 4 2
20 4 10 5 7 4
90 8 10 23 1 2 3 4 5 7
45 8 4 10 44 43 12 9 8 2
测试样例2：
45 9 
1 4 10 44 43 12 9 8 2

1 4 sum:5
8 2 sum:10
10 5 4 sum:19
10 23 1 2 3 4 5 7 sum:55
4 10 12 9 8 2 sum:45
*/ 
