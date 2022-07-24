/*
解法正确，但是时间复杂度为 O(t*I*D)，约为 t*20*5e4 
ref: 
https://zhuanlan.zhihu.com/p/506722228
https://www.cnblogs.com/zhengbin/p/4345515.html
*/ 
#include<cstdio> 
#include<cstring> 
const int maxd = 20; 
int s[1<<maxd]; //最大结点个数为2maxd-1 
int main() {
	int t, D, I;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &D, &I);
		memset(s, 0, sizeof(s)); //开关初始为关闭 
		int k, n = ( 1 << D ) - 1; //n是最大结点编号
		for(int i = 0; i < I; i++) {
			k = 1;
			while(1){
				s[k] = !s[k];
				k = s[k] ? k*2 : k*2 + 1; //根据开关状态选择下落方向
				if(k>n) break; //已经落"出界"了
			}   //连续让I个小球下落  
		} 
		printf("%d\n", k/2); // "出界"之前的叶子编号	
	}
}
