#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define inf 0x3f3f3f3f
using namespace std;
int n, q, h[50100];
int rmax[50100][20],rmin[50100][20];
void init(){
	for(int i = 1; i <= n; i++)
        rmin[i][0] = rmax[i][0] = h[i];
    //走4步由走2步得来，以此类推，j需要放在第一层循环 
    for(int j = 1; (1<<j) <= n; j++){
        for(int i = 1; i+(1<<j)-1 <= n; i++){
            rmin[i][j] = min(rmin[i][j-1], rmin[i+(1<<(j-1))][j-1]);
            rmax[i][j] = max(rmax[i][j-1], rmax[i+(1<<(j-1))][j-1]);
        }
    }
}

//method 1
int query_max_split(int l, int r){
	int L = r-l+1, ans = -inf;
	//表示从i开始走2^j步 
	for(int i = l, j = 0; (1<<j) <= L; j++)
		if(L&(1<<j)){
			ans = max(ans, rmax[i][j]);
			i += (1<<j);
		}
	return ans;
}
//method 2
int query_max(int l, int r){
	int k = log2(r-l+1);
	return max(rmax[l][k], rmax[r-(1<<k)+1][k]);
}
int query_min(int l, int r){
	int k = log2(r-l+1);
	return min(rmin[l][k],rmin[r-(1<<k)+1][k]);
}
int main(){
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    init();
    for(int i = 1; i <= q; i++){
    	int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query_max(l, r)-query_min(l, r));
    }
    return 0;
}
/*
6 3
1
7
3
4
2
5
1 5
4 6
2 2

6
3
0
*/
