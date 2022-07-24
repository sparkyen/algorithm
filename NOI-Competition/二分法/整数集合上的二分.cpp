#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e3+100;
int a[maxn] = {1, 2, 3, 4, 5};
//�ڵ������������в���>=x�����е���С��һ�� 
int findUpperId(int l, int r, int x){
	while(l<r){
		int mid = (l+r)/2;
		if(a[mid]>=x) r = mid;
		else l = mid+1;
	}
	return l;
}
//�ڵ������������в���<=x�����е�����һ��
int findLowerId(int l, int r, int x){
	while(l<r){
		int mid = (l+r+1)/2; 
		if(a[mid]<=x) l = mid;
		else r = mid-1;
	}
	return l;
}
int main(){
	cout << findUpperId(1, 6, 3) << endl;
	cout << findLowerId(0, 5, 3) << endl;
	//������ֹ�������Խ���±���˵�� a�в������������ 
	cout << findUpperId(1, 6, 7) << endl;
	cout << findLowerId(0, 5, 0) << endl;
} 
