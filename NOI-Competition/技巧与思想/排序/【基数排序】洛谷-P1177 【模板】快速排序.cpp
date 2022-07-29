#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm> 
using namespace std;
int cnt[256];//Ͱ�ŵ�Ͱ
void radixSort(int *data, int length, int radix = 256) {
    int *tmp = new int[length];//��ʱ���飬����Ͱ��Ԫ�صĴ���
    int p = 1;//Ŀǰ��λ
    for(int d = 0; d < 4; d++) {//ѭ������
    	memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < length; i++) {
            int k = (data[i] / p) % radix;//��ȡ��ǰλ������
            cnt[k]++;//��¼�����ֳ��ֵĴ���
        }
        for(int i = 1; i < radix; i++)
	        /*
	        ǰ׺�ʹ����cnt��Ϊ��ǰ���ֺ�һ�����ڹ��ɵ������е�������
	        1 5 3 4 5 5 3 
	        ���� [0, 1, 0, 2, 1, 3]���� 1����1��, 3��������.... // 1 3 3 4 5 5 5
			��ǰ׺������Ϊ[0, 1, 1, 3, 4, 7] 
	        */
            cnt[i] += cnt[i-1];
        /*
        Ϊ��֤������ȶ��ԣ��˴�ѭ��iӦ��n��1
  		������Ԫ�عؼ��ֵ�ֵ��ͬʱ��ԭ�����ں����Ԫ�����������Ӧ���ں���
  		*/
        for(int i = length - 1; i >= 0; i--) {
            int k = (data[i] / p) % radix;
            tmp[--cnt[k]] = data[i];
        }
        swap(data, tmp);//�൱�ڰ�tmp���ź�������и�����data�����Ǳ�ֱ�Ӹ���Ҫ����ࡣ
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
