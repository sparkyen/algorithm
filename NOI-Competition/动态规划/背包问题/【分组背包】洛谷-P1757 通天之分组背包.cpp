/*
分组背包+ 滚动数组优化 
*/ 
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e3+100;
int n, m, w[maxn], v[maxn], p;
int a[maxn][maxn], f[maxn][maxn], dp[maxn];
int main(){
	scanf("%d%d", &m, &n);      
	int t = -1;
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &w[i], &v[i], &p);
		a[p][++a[p][0]] = i, t = max(t, p); 
	} 
	/*
	f[k, j]表示前k组物品装到容量为j的背包的最大总重量
	和01背包相比相当于以前每一组只有一个物品 
	*/
	for(int k = 1; k <= t; k++){
		for(int j = 0; j <= m; j++){
			f[k][j] = f[k-1][j];
			for(int i = 1; i <= a[k][0]; i++){
				int id = a[k][i];
				if(j>=w[id]) f[k][j] = max(f[k][j], f[k-1][j-w[id]]+v[id]);
//				cout << f[k][j] << " ";
			}
		}
		//滚动数组优化 
//		for(int j = m; j >=0; j--){
//			for(int i = 1; i <= a[k][0]; i++){
//				int id = a[k][i];
//				if(j>=w[id]) dp[j] = max(dp[j], dp[j-w[id]]+v[id]);
//			}
//		} 
	}
	printf("%d", f[t][m]);
//	printf("%d", dp[m]);
} 
/*
测试样例：
45 3
10 10 1
10 5 1
50 400 2

10
*/
