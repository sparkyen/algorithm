#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+100;
int n, m, x;
int a[maxn];
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a+1, a+1+n);
	while(m--){
		int x, l = 1, r = n+1;
		scanf("%d", &x);
		while(l<r){
			int mid = (l+r)/2;
			if(a[mid]>=x) r = mid;
			else l = mid+1;
		}
		if(l==n+1) printf("-1\n");
		else printf("%d\n", a[l]);
	}
} 
