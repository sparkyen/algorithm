/*
��ά���ñ���+���������Ż� 
*/ 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 1e3+100; 
int n, M, T, m[maxn], t[maxn];
int dp[maxn][maxn];
int f[110][210][210];
int main(){
    scanf("%d%d%d",&n, &M, &T);
    for(int i = 1; i <= n; i++){
        /*
		f[i][u][v]��ʾǰi����Ʒ �������ַ��÷ֱ�Ϊv��uʱ�ɻ�õ�����ֵ
		����ֻ�Ƕ���һά����
		*/
        scanf("%d%d", &m[i], &t[i]);
        //���ؽⷨ 68ms
        for(int j = 0; j <= M; j++){
        	for(int k = 0; k <= T; k++){
        		f[i][j][k] = f[i-1][j][k];
        		if(j>=m[i]&&k>=t[i])
        			f[i][j][k] = max(f[i][j][k], f[i-1][j-m[i]][k-t[i]]+1);
			}
		} 
		// ���������Ż� 43ms 
//        for(int j = M; j >= m[i]; j--)
//	        for(int k = T; k >= t[i]; k--){
//	            dp[j][k] = max(dp[j][k], dp[j-m[i]][k-t[i]]+1);
//	        }
    }
//    printf("%d", dp[M][T]);
	printf("%d", f[n][M][T]);
}
/*
��������: 
6 10 10
1 1
2 3 
3 2
2 5
5 2
4 3

4
*/ 
