#include<iostream>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
const int maxn = 256+5;
char s[maxn];//�������Ľڵ�
bool failed;
struct node{
    bool have_value;//�Ƿ񱻸�ֵ��
    int v;//���ֵ
    node *left, *right;
    node(): have_value(false), left(NULL), right(NULL){} //���캯����ʼ�� 
};
node *root;
void remove_tree(node* u){
    if(u==NULL) return ;
    remove_tree(u->left);//�ݹ��ͷ��������Ŀռ�
    remove_tree(u->right);//
    delete u;
}
node* newNode(){
    return new node();
}
void addNode(int v, char* s){
    int n = strlen(s);
    node* u = root;//�Ӹ��ڵ�������
    for(int i = 0; i < n; i++){ //�ҵ���ǰλ��
        if(s[i]=='L'){
            if(u->left==NULL) u->left = newNode(); //�ڵ㲻���� �����½ڵ�
            u = u->left;
        }
        else if(s[i]=='R'){
            if(u->right==NULL) u->right = newNode();
            u = u->right;
        }
        //�����������������������Ǹ�������
    }
    if(u->have_value) failed = true;//�Ѿ�����ֵ ������������
    u->v = v;//���ڵ㸳ֵ 
    u->have_value = true;//����Ѿ���ֵ
}

//�����ַ�
bool read_input(){
    failed = false; //��¼�Ƿ���������
    //����������ʱԭ�ȵ��ڴ治����ʹ�ã���רҵ�Ƕ���˵����ͷ��ڴ�ռ��Է�ֹ�ڴ�й© 
    //�ڴ�й©ָ�������Ѷ�̬����Ķ��ڴ�����ĳ��ԭ�����δ�ͷŻ��޷��ͷţ����ϵͳ�ڴ���˷ѣ����³��������ٶȼ�������ϵͳ���������غ�� 
    remove_tree(root);
    root = newNode();//�������ڵ�
    while(1){
        if(scanf("%s",s)!=1) return false;//�����������
        if(!strcmp(s,"()")) break;//����������־ �˳�ѭ��
        int v;
        sscanf(s+1,"%d", &v);//����ڵ�ֵ
        addNode(v, strchr(s,',')+1);// strchr��������Ϊ��һ�����в��Ҹ����ַ��ĵ�һ��ƥ��֮��
    }
    return true;
}
/*
    ����һ�� ����ͽ������־��Ѿ�������  ������ֻ��Ҫ���ղ��˳����������
    �˴�ʹ��һ������������������  ��ʼʱֻ��һ�����ڵ�  Ȼ��ÿ��ȡ��һ���ڵ�
    �Ͱ����������ӽ����������
*/
bool bfs(vector<int>& ans){
    queue<node*> q;
    ans.clear();
    q.push(root);//��ʼʱֻ��һ�����ڵ�
    while(!q.empty()){
        node* u = q.front(); q.pop();
        if(!u->have_value) return false; //�нڵ�û�б���ֵ�� ������������
        ans.push_back(u->v); //���ӵ��������β��
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
