#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e5+100;
ll b, p, k;
ll qpow(ll x, ll n, ll mod){
	ll res = 1;
	while(n){
		if(n&1) res = res*x%mod;
		x = (x*x)%mod;
		n >>= 1;
	}
	return res%mod;
}
int main(){
	scanf("%lld%lld%lld", &b, &p, &k);
	printf("%lld^%lld mod %lld=%lld", b, p, k, qpow(b, p, k));
}
