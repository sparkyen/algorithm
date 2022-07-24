#include <cstdio>
#include <cstring> 
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 5e3+100, maxm = 2e5+100;
int n, m;
int fa[maxn], cnt, ans;
struct edge{
	int u, v, w;
}e[maxm];
bool cmp(edge a, edge b){
	return a.w < b.w;
}
int find(int u){
	if(u!=fa[u]) return fa[u] = find(fa[u]);
	return u;
} 
void kruskal(){
	sort(e+1, e+1+m, cmp); //将边排序 
	for(int i = 1; i <= m; i++){
		int u = find(e[i].u), v = find(e[i].v);
		if(u==v) continue;
		//将边加入生成树并统计答案 
		fa[v] = u;
		cnt++, ans += e[i].w;
	}
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++)
		cin >> e[i].u >> e[i].v >> e[i].w;
	kruskal();
	if(cnt==n-1) cout << ans;
	else puts("orz");
} 
