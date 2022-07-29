#include <cstdio>
#include <cstring>
#include <iostream>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 2e5+100;
int n, a[maxn], ans = -inf;
void maxSum(int l, int r){
	if(l==r){
		ans = max(ans, a[l]);
		return;
	}
	int mid = (l+r)>>1;
	//分治计算[l, mid]和[mid+1, r] 
	maxSum(l, mid), maxSum(mid+1, r);
	int tmp = 0, pre = -inf, suf = -inf;
	//计算最大的前缀 
	for(int i = mid; i >= l; i--){
		tmp += a[i];
		pre = max(pre, tmp);
	}
	//计算最大的后缀 
	tmp = 0;
	for(int i = mid+1; i <= r; i++){
		tmp += a[i];
		suf = max(suf, tmp);
	}
	ans = max(ans, pre+suf);
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	maxSum(1, n);
	printf("%d\n", ans);
}
/*
7
2 -4 3 -1 2 -4 3

4
*/

