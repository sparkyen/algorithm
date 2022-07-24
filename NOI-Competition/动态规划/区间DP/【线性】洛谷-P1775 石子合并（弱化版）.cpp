#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e3+100;
int n, a[maxn], sum[maxn];
int f[maxn][maxn];
int main(){
	scanf("%d", &n);
	memset(f, 0x3f, sizeof(f)); //INF
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		sum[i] = sum[i-1] + a[i];
		f[i][i] = 0; //��ʼ�� 
	} 
	for(int len = 2; len <= n; len++){ 
		for(int l = 1; l <= n-len+1; l++){ //״̬: ��˵� 
			int r = l+len-1; //״̬: �Ҷ˵� 
			for(int k = l; k < r; k++) //���� 
				f[l][r] = min(f[l][r], f[l][k]+f[k+1][r]);
			f[l][r] += sum[r]-sum[l-1];
		}
	}
	printf("%d", f[1][n]);
} 
