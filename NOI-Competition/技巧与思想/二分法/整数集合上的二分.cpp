#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e3+100;
int a[maxn] = {1, 2, 3, 4, 5};
//在单调递增序列中查找>=x的数中的最小的一个 
int findUpperId(int l, int r, int x){
	while(l<r){
		int mid = (l+r)/2;
		if(a[mid]>=x) r = mid;
		else l = mid+1;
	}
	return l;
}
//在单调递增序列中查找<=x的数中的最大的一个
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
	//二分终止于扩大的越界下标上说明 a中不存在所求的数 
	cout << findUpperId(1, 6, 7) << endl;
	cout << findLowerId(0, 5, 0) << endl;
} 
