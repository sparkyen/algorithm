#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue> 
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 4e5+100;
int n, m;
int head[maxn], cnt;
int tot, dis[maxn], ans;
bool vis[maxn];
struct edge{
	int to, val, nxt;
}e[maxn];
void add(int u, int v, int w){
	e[++cnt].to = v;
	e[cnt].val = w;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
//原版 
void prim1(){
	for(int i = 1; i <= n; i++) dis[i] = inf;
	dis[1] = 0, dis[0] = inf;
	while(true){
		int u = 0;
		//寻找距离生成树最小的顶点 
		for(int i = 1; i <= n; i++)
			if(!vis[i]&&dis[i]<dis[u])
				u = i;
		if(!u) break; //所有顶点均已加入生成树 
		tot++, vis[u] = 1, ans += dis[u];
		//更新dis数组，即生成树和其他顶点间的距离 
		for(int i = head[u]; i; i = e[i].nxt){
			int v = e[i].to, w = e[i].val;
			if(dis[v]>w) dis[v] = w;
		}
	}
} 
struct node{
	int pos, dis;
	friend bool operator <(node a, node b){
		return a.dis > b.dis;
	}
};
//堆优化 
void prim2(){
	priority_queue<node> que; //用于寻找与生成树距离最近的点 
	for(int i = 1; i <= n; i++) dis[i] = inf;
	dis[1] = 0;
	que.push({1, 0});
	while(!que.empty()){
		node now = que.top(); que.pop();
		int u = now.pos;
		if(vis[u]) continue; //若节点已经加入生成树则忽略 
		tot++, vis[u] = 1, ans += dis[u];
		for(int i = head[u]; i; i = e[i].nxt){
			int v = e[i].to, w = e[i].val;
			if(dis[v]>w) {
				dis[v] = w;
				que.push({v, w});
			}
		}
	}
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w), add(v, u, w);
	}
	prim2();
	if(tot==n) cout << ans;
	else puts("orz");
} 
