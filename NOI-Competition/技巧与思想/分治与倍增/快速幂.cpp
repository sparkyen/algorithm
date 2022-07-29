//递归实现 
ll qpow(ll x, ll n){
	if(n==0) return 1%mod; //这里取模是为了避免k=1的情况出错
	ll tmp = qpow(x, n/2);
	if(x%2==0) return tmp*tmp%mod;
	return  tmp*tmp*x%mod;
} 
//非递归实现
ll qpow(ll b, ll p){
	ll res = 1;
	while(p){
		if(n&1) res = res*x%mod //若二进制最低位为1
		x = x*x%mod;
		n >>= 1; //n二进制表示向后移一位 101101 -> 10110 
	}
}
