#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int dx[] = {0, -2, -1, 1, 2, 2, 1, -1, -2};
const int dy[] = {0, 1, 2, 2, 1, -1, -2, -2, -1};
//马可以走到的位置
int bx, by, mx, my;
ll f[40][40];
bool s[40][40]; //判断这个点有没有马拦住
int main(){
    scanf("%d%d%d%d", &bx, &by, &mx, &my);
    bx += 1, by += 1, mx += 1, my += 1; //坐标+1以防越界
    //下面两行代码表示标记马的位置
    s[mx][my] = 1;
    for(int i = 1; i <= 8; i++) s[mx+dx[i]][my+dy[i]] = 1;
    f[1][1] = 1;//初始化
    for(int i = 1; i <= bx; i++){
        for(int j = 1; j <= by; j++){
            if(s[i][j]||i*j==1) continue; // 如果被马拦住就直接跳过
            f[i][j] = f[i-1][j] + f[i][j-1]; //状态转移方程
        }
    }
    printf("%lld\n", f[bx][by]);
    return 0;
} 
