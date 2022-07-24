/*
���ر��� MLE
*/ 
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 5e4+100;
//weight, value, count ����n*log2(k)�����800����ֻ��110�Ŀռ䲻�� 
int n, m, w[800], v[800];
//���￪800ֱ��MLE���ռ���, ��С�˻�TLE������WA  
int dp[800][maxn];
int main(){
	scanf("%d%d", &n, &m);
	int cnt = 1;
	for(int i = 1; i <= n; i++){
		int tw, tv, tc, k = 1;
		scanf("%d%d%d", &tw, &tv, &tc);
		//��ԭ����n*k���Ϊn*log2(k)�� 
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
