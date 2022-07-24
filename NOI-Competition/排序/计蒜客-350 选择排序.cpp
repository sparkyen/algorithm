#include <cstdio>
using namespace std;
const int maxn = 1e3+100; 
int n, a[maxn];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++){
		int id = i, tmp;
		for(int j = i+1; j <= n; j++)
			if(a[j]<a[id]) id = j;
		if(id==i) continue;
		tmp = a[i], a[i] = a[id], a[id] = tmp;
	}
	for(int i = 1; i <= n; i++)
		printf("%d ", a[i]);
} 
/*
10
9 8 7 6 5 4 3 2 1 0
*/ 
