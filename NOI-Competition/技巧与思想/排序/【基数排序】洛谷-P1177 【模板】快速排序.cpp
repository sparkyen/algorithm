#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm> 
using namespace std;
int cnt[256];//桶排的桶
void radixSort(int *data, int length, int radix = 256) {
    int *tmp = new int[length];//临时数组，用于桶排元素的储存
    int p = 1;//目前的位
    for(int d = 0; d < 4; d++) {//循环次数
    	memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < length; i++) {
            int k = (data[i] / p) % radix;//获取当前位的数字
            cnt[k]++;//记录该数字出现的次数
        }
        for(int i = 1; i < radix; i++)
	        /*
	        前缀和处理后，cnt变为当前数字后一个数在构成的序列中的排名。
	        1 5 3 4 5 5 3 
	        例如 [0, 1, 0, 2, 1, 3]代表 1出现1次, 3出现两次.... // 1 3 3 4 5 5 5
			其前缀和数组为[0, 1, 1, 3, 4, 7] 
	        */
            cnt[i] += cnt[i-1];
        /*
        为保证排序的稳定性，此处循环i应从n到1
  		即当两元素关键字的值相同时，原先排在后面的元素在排序后仍应排在后面
  		*/
        for(int i = length - 1; i >= 0; i--) {
            int k = (data[i] / p) % radix;
            tmp[--cnt[k]] = data[i];
        }
        swap(data, tmp);//相当于把tmp中排好序的数列赋给了data，但是比直接复制要快许多。
        p *= radix;
    }
}
int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    radixSort(a, n);
    for(int i = 0; i < n; i++)
        cout << a[i] << ' ';
}
