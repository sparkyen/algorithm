#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e3+100;
int main(){
	//需要保留k位小数时，精度eps一般取eps=10^-(k+2)
	//但eps不要取得太小，否则会因为浮点小数精度的原因陷入死循环 
	while(r-l>1e-5){
		double mid = (l+r)/2;
		if(cal(mid)) r = mid;
		else l = mid;
	}
	//精度不容易确定时可以使用循环固定次数的二分法 
	for(int i = 0; i < 100; i++){
		double mid = (l+r)/2;
		if(cal(mid)) r = mid;
		else l = mid;
	} 
} 
