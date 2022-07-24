/*
多重背包 MLE
*/ 
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 5e4+100;
//weight, value, count 由于n*log2(k)大概有800多则只开110的空间不够 
int n, m, w[800], v[800];
//这里开800直接MLE爆空间了, 往小了会TLE而不是WA  
int dp[800][maxn];
int main(){
	scanf("%d%d", &n, &m);
	int cnt = 1;
	for(int i = 1; i <= n; i++){
		int tw, tv, tc, k = 1;
		scanf("%d%d%d", &tw, &tv, &tc);
		//将原来的n*k组拆为n*log2(k)组 
		while(k<tc){
			w[cnt] = k*tw, v[cnt++] = k*tv;
			tc -= k, k *= 2;
		}
		w[cnt] = tc*tw, v[cnt++] = tc*tv; 
	}	
	for(int i = 1; i <= cnt; i++){
		for(int j = 0; j <= m; j++){
			dp[i][j] = dp[i-1][j];
			if(j>=w[i]) dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
		}
	}
	printf("%d", dp[cnt][m]);
	
}
