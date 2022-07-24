/*
当前节点为u, 使用2*u, 2*u+1分别表示左右子节点
二叉树深度为n，则需要建立大小为2^n的数组, 需要较大的空间 
*/
#include <iostream>
using namespace std;
const int maxn = 1e6+100;
int tree[2*maxn];
int n, ans;
void dfs(int u, int deep) {
    if(u==0) return; //到达叶子节点时返回
    ans = max(ans, deep);//更新答案
    dfs(tree[2*u], deep+1);//向左子树遍历
    dfs(tree[2*u+1], deep+1);//向右子树遍历
}

int main() {
    cin >> n;
    //读入数据并建树
    for(int i = 1; i <= n; i++)
   		cin >> tree[2*i] >> tree[2*i+1];
    dfs(1, 1); //从1号节点出发，当前深度为1
    cout << ans << endl;
}

