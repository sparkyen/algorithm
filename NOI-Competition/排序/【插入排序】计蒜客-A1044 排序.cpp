#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e4+100;
int n, mode, a[maxn];
int main(){
	while(~scanf("%d", &n)&&n){
		scanf("%d", &mode);
		for(int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int j = 2; j <= n; j++){
	        int key = a[j]; //�������һ��Ԫ��
	        int i = j - 1;  //�����Ѿ��Ź����Ԫ�����һ��������
	        while(i>=1&&a[i]>key){
	            //�Ӻ���ǰ����Ƚ��Ѿ���������飬�������С����Ѻ�����ǰ�ߴ��棬
	            //��ʵ˵���˾�������������ƶ�һλ,Ϊ�ҵ����ʵ�λ��ʱ�����Key�Ĳ���
	            a[i+1] = a[i];
	            i--;
	        }
	        a[i+1] = key;//�ҵ����ʵ�λ���ˣ���ֵ,��i�����ĺ�������keyֵ��
	    }
	    if(!mode) {
	    	for(int i = 1; i <= n; i++) {
	    		printf("%d", a[i]);
	    		i!=n ? printf(" "): printf("\n");
			}
		}
		else{
			for(int i = n; i >= 1; i--) {
				printf("%d", a[i]);
	    		i!=1 ? printf(" "): printf("\n");
			}
		}
	    
	}
	
}
/*
6
12 3 98 1 34 2
*/
