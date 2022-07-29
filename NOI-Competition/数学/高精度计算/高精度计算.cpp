#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 1e4+100; 
char a[maxn], b[maxn];
int num;
//a>=b ����true 
bool cmp(char a[], char b[]){
	int lena = strlen(a), lenb = strlen(b);
	if(lena!=lenb) return lena>lenb;
	for(int i = 0; i < lena; i++){
		if(a[i]!=b[i]) return a[i]>b[i];
	}
	return true; 
}
void add(char a[], char b[]) {
	int p = strlen(a), q = strlen(b);
	int c[maxn], id = 0, tmp = 0;
	while(p!=0 || q!=0){
		if(p!=0) tmp += a[--p]-'0';
		if(q!=0) tmp += b[--q]-'0';
		c[id++] = tmp%10, tmp /= 10;
	}
	if(tmp) printf("1");
	for(int i = id-1; i >= 0; i--)
		printf("%d", c[i]);
}
/*
1314 1267
123 123
5 5 �ٿ�����һ�����������Ϊ 00 ʱ�����򲻻����
*/
void sub(char a[], char b[]){
	if(!cmp(a, b)) {
		printf("-");
		return sub(b, a);
	}
	int p = strlen(a), q = strlen(b);
	int c[maxn], id = 0, tmp = 0;
	while(p!=0){
		tmp = a[--p]-'0'-tmp;
		if(q!=0) tmp -= b[--q]-'0';
		c[id++] = (tmp+10)%10;
		tmp = tmp<0?1:0;
	}
	while(c[id-1]==0&&id!=1) id -= 1; //ɾ��ǰ��0 
	for(int i = id-1; i >= 0; i--)
		printf("%d", c[i]);
	
}
/*
12 12 
0 123
*/
void mul(char a[], char b[]){
	int p = strlen(a), q = strlen(b), c[2*maxn], id = p+q-1;
	for(int i = p-1; i >=0; i--)
		for(int j = q-1; j >= 0; j--)
			c[p-1-i+q-1-j] += (a[i]-'0')*(b[j]-'0');	
	for(int i = 0; i < p+q-1; i++){
		if(c[i]>9){
			c[i+1] += c[i]/10;
			c[i] %= 10;
		}	
	}
	while(c[id]==0&&id!=0) id--;
	for(int i = id; i >= 0 ; i--)
		printf("%d", c[i]);
		
}
/*
�߾����������Ե������������̺�����
9000000000 1000000000
numΪ���Χ1e9ʱ����������Ϊ9e9����int��Χ��Ҫ���䶨��Ϊlong long 
*/
void div(char a[], int num){
	int p = strlen(a);
	int c[maxn], id = 0;
	ll r = 0;
	for(int i = 0; i < p; i++){
//		cout << r << endl;
		r = r*10+a[i]-'0';
		c[id++] = r/num;
		r %= num;
	}
	bool flag = 0;
	for(int i = 0; i < id ; i++){
		if(c[i]!=0||i==id-1) flag = 1;
		if(flag) printf("%d", c[i]);	
	}
		
}
int main() {
	cin >> a >> b;
	add(a, b);

//	sub(a, b);
//	mul(a, b);

//	cin >> a >> num;
//	div(a, num);
}
