using namespace std;
const int maxn = 3e3 + 10;
int a[maxn][maxn], vis[maxn][maxn];
int n, m, edx, edy, stx, sty, ox, oy;
//edx和edy表示终点坐标, stx和sty表示起点坐标, ox和oy表示经过传送门后的坐标 
int dx[4] = {0, -1, 1, 0}, dy[4] = {1, 0, 0, -1};//四个方向 
struct Node {
	int x, y, val;
}now, node;
//now表示bfs搜索到当前点的坐标, node表示当前点能达到点的坐标(最优) 
queue <Node> q; 
inline void chuansongmen(int xx, int yy) {
	int flag = 0;//flag记录是否找到传送门的另一端 
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(!(xx == i && yy == j) && (a[i][j] == a[xx][yy])) {
				flag = 1;
				ox = i, oy = j;
			}
		}
	}//寻找传送门的另一端 
	//注意if语句中要判断不能为当前的传送门 
	if(flag == 0) {
		ox = xx, oy = yy;
	}//如果没找到, 则当前传送门没有任何用处(可以看做草堆) 
}
void bfs(int stx, int sty, int edx, int edy) {
	vis[stx][sty] = 1;
	node.x = stx, node.y = sty;
	q.push(node);
	while(q.empty() == false) {
		now = q.front();
		q.pop();
		for(int i = 0; i < 4; i++) {
			int xx = now.x + dx[i];
			int yy = now.y + dy[i];//枚举四个方向 
			if((a[xx][yy] != -1) && (a[xx][yy] != 1) && a[xx][yy] != 0) {
				chuansongmen(xx, yy);
				xx = ox;
				yy = oy;
			}//判断当前点是否为传送门, 如果是, 则开始寻找传送门另一端 
			if(xx<1||xx>n||yy<1||yy>m||a[xx][yy]==1||vis[xx][yy]==1)continue;
			//判断:达到边界、是否为玉米田、是否访问过 
			else {
				if(xx == edx && yy == edy) {
					cout << now.val + 1;//记得走到终点还要一步 
					return;
				}//判断是否到终点 
				node.x = xx, node.y = yy, node.val = now.val + 1;
				vis[xx][yy] = 1;
				q.push(node);//bfs到下一步, 存入队列, 加上标记 
			}
		}
	}
}
int main() {
	cin >> n >> m;
	char s;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> s;
			if(s=='#') a[i][j] = 1;//1为不能走的点 
			else if(s=='.') a[i][j] = 0;//0为能走的点
			else if(s=='=') {
				edx = i, edy = j;
				a[i][j] = -1;//-1为出口 
			}
			else if(s == '@') {
				stx = i, sty = j;
				a[i][j] = -1;//这里入口与出口一样并不影响 
			}
			else a[i][j] = s; 
		}
	}
	bfs(stx, sty, edx, edy); 
	return 0;
} 
