/*
桶排序 
*/
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e4+100;
//1e4 按照这种划分最多有1e3个桶，每个桶最多有1e4个数(可能有重复的元素)
int n, b[maxn/10][maxn]; 
int main(){
	scanf("%d", &n);
	int x, cnt = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		int id = x/10;
		b[id][++b[id][0]] = x;
	}
	for(int i = 0; i <= maxn/10; i++){
		sort(b[i]+1, b[i]+1+b[i][0]);
		for(int j = 1; j <= b[i][0]; j++)
			printf("%d ", b[i][j]);
	}

	
} 
