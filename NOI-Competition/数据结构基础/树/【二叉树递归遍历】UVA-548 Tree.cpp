/*
����+����ȷ��һ�Ŷ�����
����Ҫ�����򣬷����޷�ȷ��������ǰ��+���� ��
   A �� A 
  /      \ 
 B        B
*/
#include<string> 
#include<iostream> 
#include<sstream> 
#include<algorithm> 
#define inf 0x3f3f3f3f 
using namespace std;
//��Ϊ��������Ȩֵ������ͬ�Ҷ�����������ֱ����Ȩֵ��Ϊ����� 
const int maxv = 10000+10; 
int n, in_order[maxv], post_order[maxv];
int lch[maxv], rch[maxv];
bool read_list(int *a) {
	string order;
	if(!getline(cin, order)) return false;
	stringstream ss(order);
	n = 0;
	int x;
	while(ss>>x) a[n++] = x;
	return true;
} 
//��in_order[L1..r1]��post_order[l2..r2]����һ�ö���������������
int build(int l1, int r1, int l2, int r2) {
	if(l1>r1) return 0; //����
	int root = post_order[r2];
	int p = l1;
	while(in_order[p]!=root) p++;
	int cnt = p-l1; //�������Ľ�����
	lch[root] = build(l1, p-1, l2, l2+cnt-1);
	rch[root] = build(p+1, r1, l2+cnt, r2-1);
	return root;
}
int best, best_sum; //ĿǰΪֹ�����Ž�Ͷ�Ӧ��Ȩ��
void dfs(int u, int sum) {
	sum += u;
	if(!lch[u]&&!rch[u]) { //Ҷ��
		if(sum<best_sum||(sum==best_sum&&u<best)) {
			best = u;
			best_sum = sum;
		}
	}
	if(lch[u]) dfs(lch[u], sum);
	if(rch[u]) dfs(rch[u], sum);
}
int main(){
	while(read_list(in_order)){
		read_list(post_order);
		build(0, n-1, 0, n-1);
		best_sum = inf;
		dfs(post_order[n-1], 0);
		cout << best << "\n";
	}
}
/*
Sample Input
3 2 1 4 5 7 6
3 1 2 5 6 7 4
7 8 11 3 5 16 12 18
8 3 11 7 16 18 12 5
255
255
Sample Output
1
3
255
*/
