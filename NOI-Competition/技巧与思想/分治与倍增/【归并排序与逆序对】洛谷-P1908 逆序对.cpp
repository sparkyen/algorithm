#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll long long 
using namespace std;
const int maxn = 5e5+100;
int n, a[maxn], tmp[maxn];
//注意范围 
ll ans;
void merge_sort(int *a, int l, int r) {
    if (l==r) return;
    int mid = (l+r)>>1;
    merge_sort(a, l, mid), merge_sort(a, mid+1, r); //递归到更小的子问题，即分治 
    //归并 
    for(int i = l, j = mid+1, k = l; k <= r; k++) {  
    	//后段元素被用完了 或者前段现在的首元素比后段的小 
        if(j==r+1||(i<=mid&&a[i]<=a[j])) tmp[k] = a[i++];  
        else tmp[k] = a[j++], ans += mid+1-i;
    }
    for(int i = l; i <= r; i++) a[i] = tmp[i];
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	merge_sort(a, 1, n);
//	for(int i = 1; i <= n; i++)
//		printf("%d ", a[i]);
	printf("%lld", ans);
} 
/*
8
7 12 9 4 -2 6 34 1

-2 1 4 6 7 9 12 34 
*/

