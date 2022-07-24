#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
void solve(){ 
	//最朴素的解法 
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			for(int k = 0; k*w[i]<=j; j++)
				f[i][j] = max(f[i][j], f[i-1][j-k*w[i]]+k*v[i]);
		}
	}
	/*
	01背包中f[i][j]由 f[i-1][j]和f[i-1][j-w[i]] 递推而来是为了保证第i件物品只选一次
	而现在第i件物品可以选无限件 ，正好需要可能已经选入第i件物品的f[i][j-w[i]] 
	*/
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			f[i][j] = (i==1?0:f[i-1][j]);
			if(j>=w[i]) f[i][j] = max(f[i][j], f[i][j-w[i]]+v[i]); 
		}
	} 
	//滚动数组优化 
	for(int i = 1; i <= n; i++){
		for(int j = w[i]; j <= m; j++){
			f[j] = max(f[j], f[j-w[i]]+v[i]);
		}
	}
}
int main(){
	
}
