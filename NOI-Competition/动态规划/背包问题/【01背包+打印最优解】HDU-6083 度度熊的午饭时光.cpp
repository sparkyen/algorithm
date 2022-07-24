//code 1-3-1
//ref: #22475787 | yfsyfs's solution for [HDU-6083] (https://vjudge.net/solution/snapshot/22475787)
scanf("%d%d", &m, &n);
//初始化 
memset(dp, 0, sizeof(dp));
memset(path, 0, sizeof(path));
for(int i = 1; i <= n; i++) scanf("%d%d", &v[i], &w[i]);
for(int i = n; i >= 1; i--)
	for(int j = m; j >= w[i]; j--){
		if(dp[j-w[i]]+v[i]>dp[j]){ //第一关键字 
			dp[j] = dp[j-w[i]]+v[i];
			sum[j] = sum[j-w[i]]+i;
			path[i][j] = 1;
		}
		else if(dp[j-w[i]]+v[i]==dp[j]){ //第一关键字相同 
			if(sum[j-w[i]]+i<=sum[j]){ //比较第二关键字 
				sum[j] = sum[j-w[i]]+i;
				path[i][j] = 1;
			}
		}
	}
int j = m, id = 1;
for(int i = 1; i <= n; i++){
	if(path[i][j]==1){
		res[id++] = i;
		j -= w[i];
	}
}
printf("Case #%d:\n", ++k);
printf("%d %d\n", dp[m], m-j);
for(int i = 1; i <= id-1; i++){
	printf("%d", res[i]);
	printf("%c", i!=id-1 ?' ':'\n');
}