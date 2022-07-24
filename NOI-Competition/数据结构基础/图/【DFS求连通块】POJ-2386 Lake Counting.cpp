/*
DFS��BFS��������������ͨ��
����������DFS����Ӽ���д����˻���ʹ��DFS����� 

*/
#include <cstdio>
int n, m, res;
/*
���鿪С�˻ᵼ��WA��field[nx][ny]�������鷶Χ 
�Դ�POJ��ʾWA����OpenJ_Bailian����ʾTLE�����ֺ��߲�������������� 
*/ 
char field[110][110];	
void dfs(int x, int y){
	field[x][y] = '.'; //��ˮ����Ϊƽ��, ��ʾ�Ѿ������� 
	//����ˮ�ӵ�������ͨ�˴�����Ҫ��ÿ�����򶼽������� 
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
