/*
DFS和BFS都可以用于求连通块
都是搜索，DFS会更加简洁好写，因此基本使用DFS来求解 

*/
#include <cstdio>
int n, m, res;
/*
数组开小了会导致WA：field[nx][ny]超出数组范围 
对此POJ显示WA，而OpenJ_Bailian则显示TLE，发现后者不仅仅对这题如此 
*/ 
char field[110][110];	
void dfs(int x, int y){
	field[x][y] = '.'; //将水坑夷为平地, 表示已经搜索过 
	//由于水坑的连接四通八达，因此需要将每个方向都进行搜素 
	for(int dx = -1; dx <= 1; dx++){
		for(int dy = -1; dy <= 1; dy++){
			int nx = x+dx, ny = y+dy;
			if(1<=nx&&nx<=n&&1<=ny&&ny<=m&&field[nx][ny]=='W') 
				dfs(nx, ny);
		} 
	}      
}

int main(){ 
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%s", field[i]+1);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
		 	if(field[i][j]=='W') {
		 		dfs(i, j);
		 		res++;
			} 
		}
	}
	printf("%d", res);
}
