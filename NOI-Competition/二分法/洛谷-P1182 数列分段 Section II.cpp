#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+100;
int n, m, l, r;
int a[maxn];
bool check(int x){
    int tot = 0, num = 1;
    for(int i = 1; i <= n; i++){
        if(tot+a[i]<=x) tot += a[i];
        else tot = a[i], num++;
    }
    return num<=m;
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n; i++){
    	scanf("%d", &a[i]);
    	l = max(l,a[i]), r += a[i];
	}	
    while(l<r){
        int mid = l+r>>1;// (l+r)/2 
        if(check(mid)) r = mid; //>=x
        else l = mid+1;
    }
    printf("%d", l);
}
