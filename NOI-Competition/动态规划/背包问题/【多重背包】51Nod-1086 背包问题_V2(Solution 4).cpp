/*
混合背包做法   ref: https://www.cnblogs.com/Draymonder/p/7358254.html
AC: 46ms / 边输入边有时候处理 78ms (玄学)
*/ 
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int dp[50100];
int main (){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
    	int w, v, c;
    	cin >> w >> v >> c;
        if(w*c > m){ //如果  数量*重量 >= 总重量，考虑完全背包
            for(int j = w;j <= m;j++)
                dp[j] = max(dp[j], dp[j-w]+v);
        }
        else{ //否则  考虑01背包二进制写法
            int k = 1;
            while (k<c){
            	//拆分时我们就可以按照01背包求解
                for(int j = m;j >= w*k; j--)
                    dp[j] = max(dp[j], dp[j-w*k]+k*v);
                c -= k, k *= 2;
            }
            for(int j = m;j >= w*c; j--)
                dp[j] = max(dp[j],dp[j-w*c]+c*v);
        }
    }
    cout << dp[m];
}
