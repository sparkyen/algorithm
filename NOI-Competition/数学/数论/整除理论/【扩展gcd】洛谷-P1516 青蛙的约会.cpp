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
	//���k*(m-n)+zL=gcd(m-n, L)
	ll f = 1, k, z;
	//ע��gcdֻ�ԷǸ�����������
	if(m-n<0) swap(m, n), f = -1;//����m-nΪ�������
	ll d = exgcd(m-n, L, k, z); 
	if((y-x)%d!=0){
		puts("Impossible");
	} 
	else {
		k = f*k*(y-x)/d; //���k*(m-n)+zL=y-x
		k = (k%(L/d)+(L/d))%(L/d); //�����С������L 
		printf("%lld\n", k);
	}
}
