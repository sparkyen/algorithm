/*
��ǰ�ڵ�Ϊu, ʹ��2*u, 2*u+1�ֱ��ʾ�����ӽڵ�
���������Ϊn������Ҫ������СΪ2^n������, ��Ҫ�ϴ�Ŀռ� 
*/
#include <iostream>
using namespace std;
const int maxn = 1e6+100;
int tree[2*maxn];
int n, ans;
void dfs(int u, int deep) {
    if(u==0) return; //����Ҷ�ӽڵ�ʱ����
    ans = max(ans, deep);//���´�
    dfs(tree[2*u], deep+1);//������������
    dfs(tree[2*u+1], deep+1);//������������
}

int main() {
    cin >> n;
    //�������ݲ�����
    for(int i = 1; i <= n; i++)
   		cin >> tree[2*i] >> tree[2*i+1];
    dfs(1, 1); //��1�Žڵ��������ǰ���Ϊ1
    cout << ans << endl;
}

