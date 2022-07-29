#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e4+100;
int n, cnt;
int a[maxn];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <=n-1; i++){
		for(int j = 1; j <= n-i; j++)
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]), cnt++;
	}
//	for(int i = 1; i <= n; i++)
//		printf("%d ", a[i]);
	printf("%d", cnt);
} 
