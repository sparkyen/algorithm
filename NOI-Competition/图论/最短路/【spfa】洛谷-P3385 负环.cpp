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
//�ж���������ݣ�ÿ����Ҫ��ʼ��
void init(){
	for(int i = 0; i < maxn; i++) head[i] = 0; //��ʼ���ڵ�ָ��ĵ�һ���� 
	tot = 0; //ʹ�ñ����¼��� 
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
		// vis[]���ڼ�¼ÿ�����Ƿ��ڶ����� 
		vis[u] = 0;
		for(int i = head[u]; i; i = e[i].nxt){
			int v = e[i].to, w = e[i].w;
			if(dis[v]>dis[u]+w){
				dis[v] = dis[u] + w;  //�������·
				cnt[v] = cnt[u] + 1;  // ��¼���·�����ı���
				if(cnt[v]>=n) return false;  //�ж����ڸ���
				//�ɳڳɹ��Ҳ��ڶ����������
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
