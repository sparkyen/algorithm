#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 2e3+100;
int n;
char s[maxn], ans[maxn];
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf(" %c", &s[i]);
	int p = 0, q = n-1, cnt = 0;
	while (p<=q) {
		bool left = false;
		for(int i = 0; p+i<q-i; i++) { 
			if(s[p+i]<s[q-i]) {
				left = true; 
				break;
			}
			else if(s[p+i]>s[q-i]) 
				break;
		}
		if(left) ans[cnt++] = s[p++];
		else ans[cnt++] = s[q--];
	}
	
	for (int i = 0; i < n; i++) {
		if(i%80==0 && i)  printf("\n");
		printf("%c", ans[i]);
	}
}
