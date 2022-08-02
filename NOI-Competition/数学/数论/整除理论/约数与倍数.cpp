//求N的正约数集合—试除法 
for(int i = 1; i*i <= n; i++){
	if(n%i==0){
		fac[++cnt] = i;
		if(i!==n/i) fac[++cnt] = n/i;//防止i=n/i出现重复 
	}
} 
for(int i = 1; i <= cnt; i++)
	printf("%d ", fac[i]); 


// 求1~N的正约数集合—倍数法
for(int i = 1; i <= n; i++)
	for(int j = 1; j <= m/i; j++)
		fac[i*j].push_back(i);
for(int i = 1; i <= n; i++){
	for(int j = 0; j < fac[i].size(); j++)
		printf("%d", fac[i][j])
	printf("\n");
} 
