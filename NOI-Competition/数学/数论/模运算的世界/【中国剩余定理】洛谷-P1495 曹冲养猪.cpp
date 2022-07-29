#include <cstdio>
#define ll long long 
using namespace std;
const int maxn = 11;
int n;
ll r[maxn], a[maxn];
ll exgcd(ll a,ll b, ll &x, ll &y) {
	if (b==0) {
	    x = 1, y = 0;
	    return a;
	}
	ll d = exgcd(b, a % b, y, x);
	y -= (a/b)*x;
	return d;
}
ll crt(int n, ll* a, ll* r) {
  ll M = 1, x = 0;
  //M=r1*r2*...*rn
  for (int i = 1; i <= n; i++) M = M * r[i];
  for (int i = 1; i <= n; i++) {
	//mi=M/ri
    ll m = M/r[i], t, y;
    exgcd(m, r[i], t, y);  // m * t mod r[i] = 1
    x = (x + a[i]*m*t%M)%M;
  }
  return (x%M+M)%M;//保证x是正数
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d%d", &r[i], &a[i]);
	printf("%lld", crt(n, a, r));
}
/*
3
3 1
5 1
7 2

16
*/
 
