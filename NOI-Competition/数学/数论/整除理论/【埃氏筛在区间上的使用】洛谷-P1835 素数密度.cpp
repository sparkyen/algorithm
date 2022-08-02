#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 1e6+100;
ll L, R;
int cnt, pri[100100];
bool vis[100100], res[maxn]; //�����ж��Ƿ��Ǻ��������� 
int sieve(int n){
	for(int i = 2; i*i <= n; i++){
		if(!vis[i]){
			for(int j = i*i; j <= n; j += i)
				vis[j] = 1;
		}
	}
	for(int i = 2; i <= n; i++)
		if(!vis[i]) pri[++cnt] = i;
}
int main(){
	scanf("%lld%lld", &L, &R);
	//���� 1�������� 
	if(L==1) L = 2;
	sieve(50000);
	for(int i = 1; i <= cnt; i++){
		//�ó�����(>=L && %pri[i]==0)��l�������
		ll st = max(2ll, (L+pri[i]-1)/pri[i])*pri[i];
		//ɸȥ pri[i]�ı��� 
		for(ll j = st; j <= R; j += pri[i])
			res[j-L] = 1; 
	}
	int tot = 0;
	for(ll i = L; i <= R; i++)
		if(!res[i-L]) tot++;
	printf("%d", tot); 		
}
/*
2 11

5
*/
