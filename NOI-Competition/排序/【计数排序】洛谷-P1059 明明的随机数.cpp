/*
¼ÆÊýÅÅÐò 
*/
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 1e3+100;
int n, b[maxn];
int main(){
	scanf("%d", &n);
	int x, cnt = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &x);
		if(b[x]==0) cnt++;
		b[x]++;
	}
	printf("%d\n", cnt);
	for(int i = 0; i <= maxn; i++)
		if(b[i]>0) printf("%d ", i);
	
} 
