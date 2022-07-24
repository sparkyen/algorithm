#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+100;
int n, a[maxn];
int dp[maxn], ans;
void solution(){
	int res[maxn], id = 1;
	//记录其中一种解决方案,正着记录，倒着输出
	for(int i = n; i >= 1; i--){
		if(dp[i]==ans){
			res[id++] = a[i];
			ans--;
		}
	}
	for(int i = id-1; i >= 1; i--)
		printf("%d ", res[i]);
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		dp[i] = 1;
		for(int j = 1; j < i; j++)
			if(a[j]<a[i])
				dp[i] = max(dp[i], dp[j]+1);
		ans = max(ans, dp[i]);
	} 
	printf("%d\n", ans);
	solution();
}
