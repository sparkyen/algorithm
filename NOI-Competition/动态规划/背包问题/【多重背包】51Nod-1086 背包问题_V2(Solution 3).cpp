/*
多重背包二进制优化 AC: 46ms
需要注意二进制分组后的数据范围 
*/ 
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 5e4+100;
//weight, value, count 由于n*log2(k)大概有800多则只开110的空间不够 
// 并且空间开小后显示TLE而不是WA 
int n, m, w[800], v[800];
int f[maxn];

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
		//也可以这样写 
//		for(int j = 1; j < tc; j <<= 1){
//			w[cnt] = j*tw, v[cnt] = j*tv;
//			cnt++, tc -= j;
//		}
		w[cnt] = tc*tw, v[cnt++] = tc*tv; 
	}	
	for(int i = 1; i <= cnt; i++){
		for(int j = m; j >= w[i]; j--)
			f[j] = max(f[j], f[j-w[i]]+v[i]);
	}
	printf("%d", f[m]);
}
