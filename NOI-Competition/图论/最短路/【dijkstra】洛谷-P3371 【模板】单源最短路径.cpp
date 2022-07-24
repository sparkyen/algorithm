#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <queue>
#define ll long long
#define pii pair<ll, int>
//ע��ʹ��2e32-1�Ǵ���� 
#define inf 2147483647
using namespace std;
const int maxn = 1e4+100, maxm = 5e5+100; 
int n, m, s;
int head[maxn], cnt;
bool vis[maxn];
ll dis[maxn];
struct edge{
	int to, nxt, cost;
}e[maxm];
void add(int u,int v,int w){
	e[++cnt].to = v;
	e[cnt].cost = w;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}
//�������� 
void dijkstra1(int u){
	for(int i = 1; i <= n; i++) dis[i] = inf;
	dis[u] = 0;
    //ѭ��ֱ�����е��ҵ����·��
	while(!vis[u]){
		vis[u] = 1;
		for(int i = head[u]; i != 0; i = e[i].nxt){
			if(!vis[e[i].to]&&dis[e[i].to]>dis[u]+e[i].cost)
				dis[e[i].to] = dis[u]+e[i].cost;
		}
		//��δ��ǵĵ����ҳ�dis��С�ĵ� 
		ll minDis = inf;
		for(int i = 1; i <= n; i++){
			if(!vis[i]&&dis[i]<minDis){
				minDis = dis[i];
				u = i;
			}
		}
	}
}
//���Ż� 
//��С�Ķ����int�����ǻ�RE�� 
void dijkstra2(int s){
	priority_queue<pii, vector<pii>,greater<pii> >que;
	for(int i = 1; i <= n; i++) dis[i] = inf;
	dis[s] = 0, que.push(make_pair(0, s));
	while(!que.empty()){
		pii now = que.top(); que.pop();
		int u = now.second;
		if(vis[u]) continue;
        vis[u] = 1;
		for(int i = head[u]; i; i = e[i].nxt){
			int v = e[i].to;
			if(dis[v]>dis[u]+e[i].cost){
				//�ɳڲ���
				dis[v] = dis[u] + e[i].cost;
				//���±������ĵ�������
            	que.push(make_pair(dis[v], v));
			}
		}
	}
}
int main(){
	cin >> n >> m >> s;
	for(int i = 1; i <= m; i++){
		int u, v, w;
		cin >> u >> v >> w;
		add(u, v, w);
	}
	dijkstra2(s);
	for(int i = 1; i <= n; i++)
		cout << dis[i] << " ";
}

/*
5 15 5
2 2 270
1 4 89
2 1 3
5 5 261
5 2 163
5 5 275
4 5 108
4 4 231
3 4 213
3 3 119
3 1 77
3 1 6
2 4 83
5 5 196
5 5 94

166 163 2147483647 246 0 
*/
