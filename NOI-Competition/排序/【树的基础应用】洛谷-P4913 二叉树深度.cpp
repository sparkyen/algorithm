#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		if(u) g[i].pb(u);
		if(v) g[i].pb(v);
	}
	
} 
