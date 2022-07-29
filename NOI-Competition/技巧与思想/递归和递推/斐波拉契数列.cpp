#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+100;
int n, f[maxn];
int fib(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	return fib(n-1)+fib(n-2);
}
int main(){
	cin >> n;
//	cout << fib(n);
	f[1] = 1, f[2] = 1;
	for(int i = 3; i <= n; i++)
		f[i] = f[i-1]+f[i-2];
	cout << f[n];
	
} 
