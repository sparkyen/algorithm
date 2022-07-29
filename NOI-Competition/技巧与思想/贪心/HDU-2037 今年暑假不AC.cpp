#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
const int maxn = 1e5+100;
int n, s[maxn], t[maxn]; 
pii work[maxn]; 
int main(){
	while(cin>>n&&n){
		for(int i = 1; i <= n; i++)
		scanf("%d%d", &work[i].second, &work[i].first);
		sort(work+1, work+1+n);
		int ans = 0, last = 0;
		for(int i = 1; i <= n; i++){
	//		printf("%d %d\n", work[i].second, work[i].first);
			if(work[i].second>=last){
				last = work[i].first;
				ans++;
			}
		}
		printf("%d\n", ans);
	}
} 
