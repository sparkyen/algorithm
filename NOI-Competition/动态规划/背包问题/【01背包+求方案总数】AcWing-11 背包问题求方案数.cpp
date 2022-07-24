#include <iostream>
#include <cstring>
using namespace std;
const int maxn = 1010, mod = 1e9 + 7;
int n, m;
int f[maxn], g[maxn];
int main(){
    cin >> n >> m;
    for(int i = 0; i <= m; i++) g[i] = 1;//初始化时我们易知，不论是哪个体积下，总有一个对应的最大价值，方案数为1
    for(int i = 1; i <= n; i++){
        int w, v;
        cin >> w >> v;
        for(int j = m; j >= w;j--){
            if(f[j]<f[j-w]+v){
                g[j] = g[j-w]; //sitution1.选择第i个物品 
                f[j] = f[j-w]+v;
            }
            else if(f[j]==f[j-w]+v) g[j] = (g[j]+g[j-w])%mod; //sitution 2选择+不选择 第i个物品 
			//sitution 3不选择第i个物品 (g[i][j]=g[i-1][j]) 
        }
    }
    cout<< g[m] <<endl;
}
