//Ԥ���� 
void init(){
	for(int i = 1; i <= n; i++)
		f[i][0] = h[i];
	for(int j = 1; (1<<j)<=n; j++)
		for(int i = 1; i <= n-(1<<j)+1; i++)
			f[i][j] = max(f[i][j-1], f[i+(1<<j-1)][j-1]);
} 
//�����ֲ�ѯ
int RMQ(int l, int r){
	int L = r-l+1, ans = -inf;
	//��ʾ��i��ʼ��2^j�� 
	for(int i = l, j = 0; (1<<j) <= L; j++)
		if(L&(1<<j)){
			ans = max(ans, f[i][j]);
			i += (1<<j);
		}
	return ans;
}
// ����ϲ���ѯ
int RMQ(int l, int r){
	int k = log_2[r-l+1];
	return max(f[l][k], f[r-(1<<k)+1][k])
} 
