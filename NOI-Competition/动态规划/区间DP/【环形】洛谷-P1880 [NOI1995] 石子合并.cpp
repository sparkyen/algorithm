#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 110;
int n, a[maxn], sum[2*maxn];
int f[2*maxn][2*maxn], g[2*maxn][2*maxn];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= 2*n; i++){
		sum[i] += sum[i-1]+(i<=n?a[i]:a[i-n]); 
		f[i][i] = 0;
	}
	int minRes = inf, maxRes = -1;
	for(int len = 2; len <= n; len++){ 
		for(int l = 1; l+len-1<=2*n; l++){ 
			int r = l+len-1;  
			if(l>=n+1) {
				f[l][r] = f[l-n][r-n]; 
				g[l][r] = g[l-n][r-n]; 
				continue;
			}
			for(int k = l; k < r; k++) {
				f[l][r] = min(f[l][r], f[l][k]+f[k+1][r]);
				g[l][r] = max(g[l][r], g[l][k]+g[k+1][r]);
			}		
			f[l][r] += sum[r]-sum[l-1];
			g[l][r] += sum[r]-sum[l-1];
			if(len==n) {
				minRes = min(minRes, f[l][r]);
				maxRes = max(maxRes, g[l][r]);
			}
		}
	}
	printf("%d\n%d", minRes, maxRes);
} 
