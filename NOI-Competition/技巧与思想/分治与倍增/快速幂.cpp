//�ݹ�ʵ�� 
ll qpow(ll x, ll n){
	if(n==0) return 1%mod; //����ȡģ��Ϊ�˱���k=1���������
	ll tmp = qpow(x, n/2);
	if(x%2==0) return tmp*tmp%mod;
	return  tmp*tmp*x%mod;
} 
//�ǵݹ�ʵ��
ll qpow(ll b, ll p){
	ll res = 1;
	while(p){
		if(n&1) res = res*x%mod //�����������λΪ1
		x = x*x%mod;
		n >>= 1; //n�����Ʊ�ʾ�����һλ 101101 -> 10110 
	}
}
