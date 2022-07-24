/*
���ر����������� AC: 593ms
������Ҫ����� ���������ݽ��е���, ��������������ᳬʱ, �ǳ�����ѧ 
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 5e4+100;
//weight, value, count
int n, m, w[110], v[110], c[110];
int dp[110][maxn];
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d%d%d", &w[i], &v[i], &c[i]);
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			for(int k = 0; k<=c[i]&&k*w[i]<=j; k++)
				dp[i][j] = max(dp[i][j], dp[i-1][j-k*w[i]]+k*v[i]);
		}
	}
	printf("%d", dp[n][m]);
	
}
/*
��������:
3 6
2 2 5
3 3 8
1 4 1
*/ 
