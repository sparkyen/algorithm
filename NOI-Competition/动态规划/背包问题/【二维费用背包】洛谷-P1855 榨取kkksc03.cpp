/*
二维费用背包+滚动数组优化 
*/ 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1e3+100; 
int n, M, T, m[maxn], t[maxn];
int dp[maxn][maxn];
int f[110][210][210];
int main(){
    scanf("%d%d%d",&n, &M, &T);
    for(int i = 1; i <= n; i++){
        /*
		f[i][u][v]表示前i件物品 付出两种费用分别为v和u时可获得的最大价值
		仅仅只是多了一维而已
		*/
        scanf("%d%d", &m[i], &t[i]);
        //朴素解法 68ms
        for(int j = 0; j <= M; j++){
        	for(int k = 0; k <= T; k++){
        		f[i][j][k] = f[i-1][j][k];
        		if(j>=m[i]&&k>=t[i])
        			f[i][j][k] = max(f[i][j][k], f[i-1][j-m[i]][k-t[i]]+1);
			}
		} 
		// 滚动数组优化 43ms 
//        for(int j = M; j >= m[i]; j--)
//	        for(int k = T; k >= t[i]; k--){
//	            dp[j][k] = max(dp[j][k], dp[j-m[i]][k-t[i]]+1);
//	        }
    }
//    printf("%d", dp[M][T]);
	printf("%d", f[n][M][T]);
}
/*
测试样例: 
6 10 10
1 1
2 3 
3 2
2 5
5 2
4 3

4
*/ 
