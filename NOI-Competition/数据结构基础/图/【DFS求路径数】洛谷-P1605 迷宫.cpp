/*
dfs: 一条路走到黑 
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e3+100;
int n, m, t, sx, sy, fx, fy;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int vis[maxn][maxn], cnt; 
void dfs(int x, int y){
	//边界外或者访问过就返回 
	if((x<1||x>n||y<1||y>m)||vis[x][y]) return;
	if(x==fx&&y==fy){
		cnt++;
		return;
	}
	vis[x][y] = 1; //占位, 防止往回走 
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i], ny = y+dy[i];
		dfs(nx, ny);
	}
	vis[x][y] = 0; //取消占位(回溯), 空出占用的位置 
	/*
	# # # $ # 
	. . # . .
	# # . . #
	. . . . #
	# # . . #
	# # @ # #
	*/ 
} 
int main(){
	scanf("%d%d%d", &n, &m, &t);
	scanf("%d%d%d%d", &sx, &sy, &fx, &fy);
	while(t--){
		int x, y;
		scanf("%d%d", &x, &y);
		vis[x][y] = 2;
	}
	dfs(sx, sy);
	printf("%d", cnt);
	
} 
