#include <cstdio>
using namespace std;
const int maxn = 1e3+100;
int n, m;
int fa[maxn];
//���鼯Ѱ�Ҹ��ڵ㣨��·��ѹ���� 
int find(int u){
	if(u!=fa[u]) return fa[u] = find(fa[u]);
	return u;
}
//�ϲ� 
void unite(int u, int v){
	u = find(u), v = find(v);
	if(u!=v) fa[v] = u;
} 
int main(){
	while(~scanf("%d", &n)&&n){
		scanf("%d", &m);
		for(int i = 1; i <= n; i++) fa[i] = i;
		for(int i = 1; i <= m; i++){
			int u, v;
			scanf("%d%d", &u, &v);
			unite(u, v);
		}
		int cnt = 0;
		//ȷ����ͨ��������  
		for(int i = 1; i <= n; i++)
			if(fa[i]==i) cnt++;
		printf("%d\n", cnt-1);
	}
}
