#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
void solve(){ 
	//�����صĽⷨ 
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			for(int k = 0; k*w[i]<=j; j++)
				f[i][j] = max(f[i][j], f[i-1][j-k*w[i]]+k*v[i]);
		}
	}
	/*
	01������f[i][j]�� f[i-1][j]��f[i-1][j-w[i]] ���ƶ�����Ϊ�˱�֤��i����Ʒֻѡһ��
	�����ڵ�i����Ʒ����ѡ���޼� ��������Ҫ�����Ѿ�ѡ���i����Ʒ��f[i][j-w[i]] 
	*/
	for(int i = 1; i <= n; i++){
		for(int j = 0; j <= m; j++){
			f[i][j] = (i==1?0:f[i-1][j]);
			if(j>=w[i]) f[i][j] = max(f[i][j], f[i][j-w[i]]+v[i]); 
		}
	} 
	//���������Ż� 
	for(int i = 1; i <= n; i++){
		for(int j = w[i]; j <= m; j++){
			f[j] = max(f[j], f[j-w[i]]+v[i]);
		}
	}
}
int main(){
	
}
