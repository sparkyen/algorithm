#include<algorithm>
#include <iostream>
using namespace std;
const int maxn = 1e3+100;
int n, r;
int dis[maxn];
int main(){
	while(cin>>r>>n && r!=-1) {
        for(int i = 0; i < n; i++) cin >> dis[i];
        sort(dis, dis+n);
		int i = 0, ans = 0;
		while (i<n) {
			int s = dis[i];
			while (i<n && dis[i] <= s+r) i++;
			int p = dis[i-1];
			while (i<n && dis[i] <= p+r) i++;
			ans++;
		}
		printf("%d\n", ans);
    }
} 
