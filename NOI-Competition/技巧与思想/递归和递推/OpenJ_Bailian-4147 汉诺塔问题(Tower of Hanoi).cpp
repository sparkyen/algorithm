#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, cnt;
char a, b, c;
void move(int n, char a, char c, char b){
	if(n==0) return;
	move(n-1, a, b, c);
	cout << n << ":" << a << "->" << c << endl;
	move(n-1, b, c, a);
}
int main(){
	cin >> n >> a >> b >> c;
	move(n, a, c, b);
} 
