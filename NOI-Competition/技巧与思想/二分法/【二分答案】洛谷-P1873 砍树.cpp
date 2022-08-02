#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 1e6+100;
ll n, m, a[maxn];
bool check(int x){
	ll tot = 0;
	for(int i = 1; i <= n; i++)
		if(a[i]>x) tot += a[i]-x;
	return tot >= m;
}
int main(){
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	int l = 0, r = 1e9;
	while(l<r){
		//二分的取法要特别注意 
		int mid = (l+r+1)>>1;
		if(check(mid)) l = mid;
		else r = mid-1;
//		cout << mid << endl;
	}
	printf("%lld", l);
}
