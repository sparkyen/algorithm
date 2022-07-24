/*
使用结构体node来表示当前节点存储的信息 
*/ 
#include <iostream>
using namespace std;
const int maxn = 1e6+100;
/*
为什么结点有时要用指针实现？
使用数组或是指针来进行索引，功能上是等同的。
但如果用数组表示，会有一个问题：
数组是在定义时候确定大小，并且以后无法改变的；
如果在编制程序之初无法确定有多少个节点，怎么办？
而指针在使用上则更为简单。因此，具体的设计中，会倾向于使用指针。
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
