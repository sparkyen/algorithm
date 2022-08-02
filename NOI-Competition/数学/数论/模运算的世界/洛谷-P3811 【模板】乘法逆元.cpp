#include<cstdio>
#define ll long long
using namespace std;
const int maxn=3e6+5;
int n, p;
ll inv[maxn]={0,1};
int main(){
	scanf("%d%d", &n, &p);
	printf("1\n");
	for(int i = 2; i <= n; i++){
		inv[i] = p-(p/i)*inv[p%i]%p;
		printf("%d\n",inv[i]);
	}
}
