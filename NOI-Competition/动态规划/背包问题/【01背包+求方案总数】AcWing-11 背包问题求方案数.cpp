#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1010, mod = 1e9 + 7;
int n, m;
int f[maxn], g[maxn];
int main(){
    cin >> n >> m;
    for(int i = 0; i <= m; i++) g[i] = 1;//��ʼ��ʱ������֪���������ĸ�����£�����һ����Ӧ������ֵ��������Ϊ1
    for(int i = 1; i <= n; i++){
        int w, v;
        cin >> w >> v;
        for(int j = m; j >= w;j--){
            if(f[j]<f[j-w]+v){
                g[j] = g[j-w]; //sitution1.ѡ���i����Ʒ 
                f[j] = f[j-w]+v;
            }
            else if(f[j]==f[j-w]+v) g[j] = (g[j]+g[j-w])%mod; //sitution 2ѡ��+��ѡ�� ��i����Ʒ 
			//sitution 3��ѡ���i����Ʒ (g[i][j]=g[i-1][j]) 
        }
    }
    cout<< g[m] <<endl;
}
