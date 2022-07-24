#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
void solve(){ 
	/*
	f(i, j)表示把"i,i+1,...,n"个物品装到容量为j的背包的最大总重量
	答案是d[1][m] 
	*/ 
	for(int i = n; i >= 1; i--)
		for(int j = 0; j <= m; j++){
			f[i][j] = (i==n?0:d[i+1][j]);
			if(j>=w[i]) f[i][j] = max(f[i][j], f[i+1][j-w[i]]+v[i]);
		}
	/*
	f(i, j)表示把"1,2,...,i"个物品装到容量为j的背包的最大总重量
	答案是f[n][m] 
	*/ 
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= m; j++){
			f[i][j] = f[i-1][j];
			if(j>=w[i]) f[i][j] = max(f[i][j], f[i-1][j-w[i]]+v[i]);
		}
	//新的状态允许边读边读入计算而不必保存 
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &w, &v);
		for(int j = 0; j <= m; j++){
			f[i][j] = (i==1?0:f[i-1][j]);
			if(j>=w) f[i][j] = max(f[i][j], f[i-1][j-w]+v);
		}
	}
	/*
	滚动数组优化空间
	但是导致只有最后一个阶段的状态值，不好打印解 
	不过就算是二维数组仍然不能保证是最小字典序的解，因为是逆向打印 
	*/
	for(int i = 1; i <= n; i++){
		//scanf("%d%d", &v, &w);
		//需要倒着遍历保证当前为i时f[j]都是f[i-1][j] 
		for(int j = m; j >= 0; j--){
			if(j>=v) f[j] = max(f[j], f[j-v]+w);
		}
	}
	/*
	优化空间+记录路径+最小字典序的打印解
	ref: #37069276 | Yi_Shan's solution for [UVA-624] [Problem F]
	*/
	for(int i = n; i >= 1; i--)
		for(int j = m; j >= v[i]; j--){
			//只有取>=才能保证字典序最小 
			if(f[j-v[i]]+w[i]>=f[j]){
				f[j] = f[j-v[i]]+w[i];
				path[i][j] = 1;
			}
		}
	int j = m;
	for(int i = 1; i <= n; i++){
		if(path[i][j]==1){
			cout << i << " ";
			j -= v[i];
		}
	}		
}
int main(){
	solve(); 
} 
