#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e3+100;
int main(){
	//��Ҫ����kλС��ʱ������epsһ��ȡeps=10^-(k+2)
	//��eps��Ҫȡ��̫С���������Ϊ����С�����ȵ�ԭ��������ѭ�� 
	while(r-l>1e-5){
		double mid = (l+r)/2;
		if(cal(mid)) r = mid;
		else l = mid;
	}
	//���Ȳ�����ȷ��ʱ����ʹ��ѭ���̶������Ķ��ַ� 
	for(int i = 0; i < 100; i++){
		double mid = (l+r)/2;
		if(cal(mid)) r = mid;
		else l = mid;
	} 
} 
