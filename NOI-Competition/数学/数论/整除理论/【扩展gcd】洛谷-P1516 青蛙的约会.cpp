#include <cstdio>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll x, y, m, n, L;
ll exgcd(ll a, ll b, ll &x, ll &y){
	if(b==0){
		x = 1, y = 0;
		return a;
	}
	ll d = exgcd(b, a%b, y, x);
	y -= (a/b)*x;
	return d;
}
int main(){
	scanf("%lld%lld%lld%lld%lld", &x, &y, &m, &n, &L);  
	//求解k*(m-n)+zL=gcd(m-n, L)
	ll f = 1, k, z;
	//注意gcd只对非负整数有意义
	if(m-n<0) swap(m, n), f = -1;//处理m-n为负数情况
	ll d = exgcd(m-n, L, k, z); 
	if((y-x)%d!=0){
		puts("Impossible");
	} 
	else {
		k = f*k*(y-x)/d; //求解k*(m-n)+zL=y-x
		k = (k%(L/d)+(L/d))%(L/d); //求出最小的正数L 
		printf("%lld\n", k);
	}
}
