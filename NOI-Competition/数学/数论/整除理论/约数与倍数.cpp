//��N����Լ�����ϡ��Գ��� 
for(int i = 1; i*i <= n; i++){
	if(n%i==0){
		fac[++cnt] = i;
		if(i!==n/i) fac[++cnt] = n/i;//��ֹi=n/i�����ظ� 
	}
} 
for(int i = 1; i <= cnt; i++)
	printf("%d ", fac[i]); 


// ��1~N����Լ�����ϡ�������
for(int i = 1; i <= n; i++)
	for(int j = 1; j <= m/i; j++)
		fac[i*j].push_back(i);
for(int i = 1; i <= n; i++){
	for(int j = 0; j < fac[i].size(); j++)
		printf("%d", fac[i][j])
	printf("\n");
} 
