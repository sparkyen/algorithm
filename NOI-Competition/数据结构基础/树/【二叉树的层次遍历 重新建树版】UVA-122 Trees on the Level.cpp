#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 256+5;
char s[maxn];//保存读入的节点
bool failed;
struct node{
    bool have_value;//是否被赋值过
    int v;//结点值
    node *left, *right;
    node(): have_value(false), left(NULL), right(NULL){} //构造函数初始化 
};
node *root;
void remove_tree(node* u){
    if(u==NULL) return ;
    remove_tree(u->left);//递归释放左子树的空间
    remove_tree(u->right);//
    delete u;
}
node* newNode(){
    return new node();
}
void addNode(int v, char* s){
    int n = strlen(s);
    node* u = root;//从根节点往下走
    for(int i = 0; i < n; i++){ //找到当前位置
        if(s[i]=='L'){
            if(u->left==NULL) u->left = newNode(); //节点不存在 建立新节点
            u = u->left;
        }
        else if(s[i]=='R'){
            if(u->right==NULL) u->right = newNode();
            u = u->right;
        }
        //忽略其他情况，即最后多余的那个右括号
    }
    if(u->have_value) failed = true;//已经赋过值 表明输入有误
    u->v = v;//给节点赋值 
    u->have_value = true;//标记已经赋值
}

//读入字符
bool read_input(){
    failed = false; //记录是否输入有误
    //输入新数据时原先的内存不会再使用，从专业角度来说最好释放内存空间以防止内存泄漏 
    //内存泄漏指程序中已动态分配的堆内存由于某种原因程序未释放或无法释放，造成系统内存的浪费，导致程序运行速度减慢甚至系统崩溃等严重后果 
    remove_tree(root);
    root = newNode();//创建根节点
    while(1){
        if(scanf("%s",s)!=1) return false;//整个输入结束
        if(!strcmp(s,"()")) break;//读到结束标志 退出循环
        int v;
        sscanf(s+1,"%d", &v);//读入节点值
        addNode(v, strchr(s,',')+1);// strchr函数功能为在一个串中查找给定字符的第一个匹配之处
    }
    return true;
}
/*
    这样一来 输入和建树部分就已经结束了  接下来只需要按照层次顺序遍历这棵树
    此处使用一个队列来完成这个任务  初始时只有一个根节点  然后每次取出一个节点
    就把它的左右子结点放入队列中
*/
bool bfs(vector<int>& ans){
    queue<node*> q;
    ans.clear();
    q.push(root);//初始时只有一个根节点
    while(!q.empty()){
        node* u = q.front(); q.pop();
        if(!u->have_value) return false; //有节点没有被赋值过 表明输入有误
        ans.push_back(u->v); //增加到输出序列尾部
        if(u->left!=NULL) q.push(u->left);
        if(u->right!=NULL) q.push(u->right);
    }
    return true;
}

int main(){
    while(read_input()){
        vector<int> ans;
        if(failed||(!bfs(ans))) printf("not complete\n");
        else{
            vector<int>::iterator it = ans.begin();
            printf("%d", *it), it++;
            for(it; it!=ans.end(); it++)
                printf(" %d",*it);
            printf("\n");
        }
    }
}
/*
Sample Input
(11,LL) (7,LLL) (8,R)
(5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
(3,L) (4,R) ()
Sample Output
5 4 8 11 13 4 7 2 1
not complete
*/
