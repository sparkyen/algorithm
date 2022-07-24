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
//ԭ�� 
void prim1(){
	for(int i = 1; i <= n; i++) dis[i] = inf;
	dis[1] = 0, dis[0] = inf;
	while(true){
		int u = 0;
		//Ѱ�Ҿ�����������С�Ķ��� 
		for(int i = 1; i <= n; i++)
			if(!vis[i]&&dis[i]<dis[u])
				u = i;
		if(!u) break; //���ж�����Ѽ��������� 
		tot++, vis[u] = 1, ans += dis[u];
		//����dis���飬�������������������ľ��� 
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
//���Ż� 
void prim2(){
	priority_queue<node> que; //����Ѱ������������������ĵ� 
	for(int i = 1; i <= n; i++) dis[i] = inf;
	dis[1] = 0;
	que.push({1, 0});
	while(!que.empty()){
		node now = que.top(); que.pop();
		int u = now.pos;
		if(vis[u]) continue; //���ڵ��Ѿ���������������� 
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
