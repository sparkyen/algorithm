#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 110;
int n, a[2*maxn];
int f[2*maxn][2*maxn];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		a[i+n] = a[i];
	}	
	int res = 0;
	for(int len = 2; len <= n; len++){
		for(int l = 1; l+len-1 <= 2*n; l++){
			int r = l+len-1;
			for(int k = l; k < r; k++)
				f[l][r] = max(f[l][r], f[l][k]+f[k+1][r]+a[l]*a[k+1]*a[r+1]);
			if(len==n) res = max(res, f[l][r]);
		}
	}
	printf("%d", res);
} 
/*
4
2 3 5 10

710
*/
