/*
���ر����������Ż� AC: 46ms
��Ҫע������Ʒ��������ݷ�Χ 
*/ 
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 5e4+100;
//weight, value, count ����n*log2(k)�����800����ֻ��110�Ŀռ䲻�� 
// ���ҿռ俪С����ʾTLE������WA 
int n, m, w[800], v[800];
int f[maxn];

int main(){
	scanf("%d%d", &n, &m);
	int cnt = 1;
	for(int i = 1; i <= n; i++){
		int tw, tv, tc, k = 1;
		scanf("%d%d%d", &tw, &tv, &tc);
		//��ԭ����n*k���Ϊn*log2(k)�� 
		while(k<tc){
			w[cnt] = k*tw, v[cnt++] = k*tv;
			tc -= k, k *= 2;
		}
		//Ҳ��������д 
//		for(int j = 1; j < tc; j <<= 1){
//			w[cnt] = j*tw, v[cnt] = j*tv;
//			cnt++, tc -= j;
//		}
		w[cnt] = tc*tw, v[cnt++] = tc*tv; 
	}	
	for(int i = 1; i <= cnt; i++){
		for(int j = m; j >= w[i]; j--)
			f[j] = max(f[j], f[j-w[i]]+v[i]);
	}
	printf("%d", f[m]);
}
