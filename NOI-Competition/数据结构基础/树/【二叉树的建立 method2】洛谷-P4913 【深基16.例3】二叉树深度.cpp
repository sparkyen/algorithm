/*
ʹ�ýṹ��node����ʾ��ǰ�ڵ�洢����Ϣ 
*/ 
#include <iostream>
using namespace std;
const int maxn = 1e6+100;
/*
Ϊʲô�����ʱҪ��ָ��ʵ�֣�
ʹ���������ָ���������������������ǵ�ͬ�ġ�
������������ʾ������һ�����⣺
�������ڶ���ʱ��ȷ����С�������Ժ��޷��ı�ģ�
����ڱ��Ƴ���֮���޷�ȷ���ж��ٸ��ڵ㣬��ô�죿
��ָ����ʹ�������Ϊ�򵥡���ˣ����������У���������ʹ��ָ�롣
*/ 
struct node {
    int left, right;
}tree[maxn];
int n, ans;
void dfs(int id, int deep) {
    if (id==0) return ; 
    ans = max(ans, deep);
    dfs(tree[id].left, deep+1);
    dfs(tree[id].right, deep+1);
}

int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
   		cin >> tree[i].left >> tree[i].right;
    dfs(1, 1);
    cout << ans << endl;
}
