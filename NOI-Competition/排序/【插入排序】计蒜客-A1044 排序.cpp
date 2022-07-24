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
	        int key = a[j]; //待排序第一个元素
	        int i = j - 1;  //代表已经排过序的元素最后一个索引数
	        while(i>=1&&a[i]>key){
	            //从后向前逐个比较已经排序过数组，如果比它小，则把后者用前者代替，
	            //其实说白了就是数组逐个后移动一位,为找到合适的位置时候便于Key的插入
	            a[i+1] = a[i];
	            i--;
	        }
	        a[i+1] = key;//找到合适的位置了，赋值,在i索引的后面设置key值。
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
