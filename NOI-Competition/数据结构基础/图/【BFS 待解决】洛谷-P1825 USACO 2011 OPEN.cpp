using namespace std;
const int maxn = 3e3 + 10;
int a[maxn][maxn], vis[maxn][maxn];
int n, m, edx, edy, stx, sty, ox, oy;
//edx��edy��ʾ�յ�����, stx��sty��ʾ�������, ox��oy��ʾ���������ź������ 
int dx[4] = {0, -1, 1, 0}, dy[4] = {1, 0, 0, -1};//�ĸ����� 
struct Node {
	int x, y, val;
}now, node;
//now��ʾbfs��������ǰ�������, node��ʾ��ǰ���ܴﵽ�������(����) 
queue <Node> q; 
inline void chuansongmen(int xx, int yy) {
	int flag = 0;//flag��¼�Ƿ��ҵ������ŵ���һ�� 
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(!(xx == i && yy == j) && (a[i][j] == a[xx][yy])) {
				flag = 1;
				ox = i, oy = j;
			}
		}
	}//Ѱ�Ҵ����ŵ���һ�� 
	//ע��if�����Ҫ�жϲ���Ϊ��ǰ�Ĵ����� 
	if(flag == 0) {
		ox = xx, oy = yy;
	}//���û�ҵ�, ��ǰ������û���κ��ô�(���Կ����ݶ�) 
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
			int yy = now.y + dy[i];//ö���ĸ����� 
			if((a[xx][yy] != -1) && (a[xx][yy] != 1) && a[xx][yy] != 0) {
				chuansongmen(xx, yy);
				xx = ox;
				yy = oy;
			}//�жϵ�ǰ���Ƿ�Ϊ������, �����, ��ʼѰ�Ҵ�������һ�� 
			if(xx<1||xx>n||yy<1||yy>m||a[xx][yy]==1||vis[xx][yy]==1)continue;
			//�ж�:�ﵽ�߽硢�Ƿ�Ϊ������Ƿ���ʹ� 
			else {
				if(xx == edx && yy == edy) {
					cout << now.val + 1;//�ǵ��ߵ��յ㻹Ҫһ�� 
					return;
				}//�ж��Ƿ��յ� 
				node.x = xx, node.y = yy, node.val = now.val + 1;
				vis[xx][yy] = 1;
				q.push(node);//bfs����һ��, �������, ���ϱ�� 
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
			if(s=='#') a[i][j] = 1;//1Ϊ�����ߵĵ� 
			else if(s=='.') a[i][j] = 0;//0Ϊ���ߵĵ�
			else if(s=='=') {
				edx = i, edy = j;
				a[i][j] = -1;//-1Ϊ���� 
			}
			else if(s == '@') {
				stx = i, sty = j;
				a[i][j] = -1;//������������һ������Ӱ�� 
			}
			else a[i][j] = s; 
		}
	}
	bfs(stx, sty, edx, edy); 
	return 0;
} 
