/*
floyd求最短路+输出方案 
ref: https://vjudge.net/solution/32201255
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e3+100;
int n, tax[maxn];
//pre[i][j]表示i到j的路径上的首个中转城市, 这是最关键的地方
int f[maxn][maxn], pre[maxn][maxn];
void floyd(){
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++){
				if(f[i][j]>f[i][k]+f[k][j]+tax[k]){
					f[i][j] = f[i][k]+f[k][j]+tax[k];
					pre[i][j] = pre[i][k];
				}
				else if(f[i][j]==f[i][k]+f[k][j]+tax[k]&&pre[i][j]>pre[i][k])
					pre[i][j] = pre[i][k];
			}
}
int main(){
	while(~scanf("%d", &n)&&n){
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++){
				scanf("%d", &f[i][j]);
				if(f[i][j]==-1) f[i][j] = inf;
				pre[i][j] = j;
			}
		for(int i = 1; i <=n; i++)
			scanf("%d", &tax[i]);
		floyd();
		int u, v;
		while(scanf("%d%d", &u, &v)&&(u!=-1||v!=-1)){
			printf("From %d to %d:\n", u, v);
			printf("Path: %d", u);
			int st = u, ed = v;
			while(st!=ed){
				printf("-->%d", pre[st][ed]);
				st = pre[st][ed];
			}
			printf("\nTotal cost:%d\n", f[u][v]);
		}
	}
}
