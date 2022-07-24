#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
void solve(){ 
	/*
	f(i, j)��ʾ��"i,i+1,...,n"����Ʒװ������Ϊj�ı��������������
	����d[1][m] 
	*/ 
	for(int i = n; i >= 1; i--)
		for(int j = 0; j <= m; j++){
			f[i][j] = (i==n?0:d[i+1][j]);
			if(j>=w[i]) f[i][j] = max(f[i][j], f[i+1][j-w[i]]+v[i]);
		}
	/*
	f(i, j)��ʾ��"1,2,...,i"����Ʒװ������Ϊj�ı��������������
	����f[n][m] 
	*/ 
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= m; j++){
			f[i][j] = f[i-1][j];
			if(j>=w[i]) f[i][j] = max(f[i][j], f[i-1][j-w[i]]+v[i]);
		}
	//�µ�״̬����߶��߶����������ر��� 
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &w, &v);
		for(int j = 0; j <= m; j++){
			f[i][j] = (i==1?0:f[i-1][j]);
			if(j>=w) f[i][j] = max(f[i][j], f[i-1][j-w]+v);
		}
	}
	/*
	���������Ż��ռ�
	���ǵ���ֻ�����һ���׶ε�״ֵ̬�����ô�ӡ�� 
	���������Ƕ�ά������Ȼ���ܱ�֤����С�ֵ���Ľ⣬��Ϊ�������ӡ 
	*/
	for(int i = 1; i <= n; i++){
		//scanf("%d%d", &v, &w);
		//��Ҫ���ű�����֤��ǰΪiʱf[j]����f[i-1][j] 
		for(int j = m; j >= 0; j--){
			if(j>=v) f[j] = max(f[j], f[j-v]+w);
		}
	}
	/*
	�Ż��ռ�+��¼·��+��С�ֵ���Ĵ�ӡ��
	ref: #37069276 | Yi_Shan's solution for [UVA-624] [Problem F]
	*/
	for(int i = n; i >= 1; i--)
		for(int j = m; j >= v[i]; j--){
			//ֻ��ȡ>=���ܱ�֤�ֵ�����С 
			if(f[j-v[i]]+w[i]>=f[j]){
				f[j] = f[j-v[i]]+w[i];
				path[i][j] = 1;
			}
		}
	int j = m;
	for(int i = 1; i <= n; i++){
		if(path[i][j]==1){
			cout << i << " ";
			j -= v[i];
		}
	}		
}
int main(){
	solve(); 
} 
