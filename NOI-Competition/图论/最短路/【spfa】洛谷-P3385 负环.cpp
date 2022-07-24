#include<cstdio>
#include<cstring>
#include<queue>
#define inf 0x3f3f3f 
const int maxn = 2e3+100, maxm = 6e3+100;
using namespace std;
int n, m;
int dis[maxn], vis[maxn], cnt[maxn];
int head[maxn], tot;
struct edge{
	int to, nxt, w;
}e[maxm]; 
//有多组测试数据，每次需要初始化
void init(){
	for(int i = 0; i < maxn; i++) head[i] = 0; //初始化节点指向的第一条边 
	tot = 0; //使得边重新计数 
}
void add(int u, int v, int w){
	e[++tot].to = v;
	e[tot].w = w;
	e[tot].nxt = head[u];
	head[u] = tot;
}
bool spfa(){
	queue<int> que;
	for(int i = 1; i <= n; i++)
		dis[i] = inf, vis[i] = 0, cnt[i] = 0;
	dis[1] = 0, vis[1] = 1;
	que.push(1);
	while(!que.empty()){
		int u = que.front(); que.pop();
		// vis[]用于记录每个点是否处在队列中 
		vis[u] = 0;
		for(int i = head[u]; i; i = e[i].nxt){
			int v = e[i].to, w = e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v] = dis[u] + w;  //更新最短路
				cnt[v] = cnt[u] + 1;  // 记录最短路经过的边数
				if(cnt[v]>=n) return false;  //判定存在负环
				//松弛成功且不在队列中则入队
				if(!vis[v]) que.push(v), vis[v] = 1;
			}
		}
	}
	return true;
}
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		init();
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= m; i++){
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			if(w>=0) add(v, u, w);
		}
		puts(!spfa()?"YES":"NO");
	}
}
