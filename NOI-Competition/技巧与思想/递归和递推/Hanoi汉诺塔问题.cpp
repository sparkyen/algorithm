#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+100;
int n, cnt;
int h[maxn];
void move(int n, char a, char c, char b){
	if(n==0) return;
	move(n-1, a, b, c);
	cnt++; //记录移动步数 
	cout << a << "->" << c << endl;
	move(n-1, b, c, a);
}
int main(){
	cin >> n;
	move(n, 'a', 'c', 'b');
//	h[1] = 1;
//	for(int i = 2; i <= n; i++)
//		h[i] = 2*h[i-1] + 1;
//	cout << cnt << " " << h[n];
} 
