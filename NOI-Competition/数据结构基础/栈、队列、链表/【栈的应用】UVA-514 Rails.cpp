/*
目标序列可按照进栈顺序1~n出栈形成，需判断目标序列是否合理 
*/
#include<cstdio>
#include<stack>
using namespace std;
const int maxn = 1e3+100;
int n, target[maxn];
int main() {
	while(~scanf("%d", &n)&&n){
		while(true){
			stack<int> s;
			int A = 1, B = 1;
			//注意输入细节 
			scanf("%d", &target[1]);
			if(target[1]==0) break;
			for(int i = 2; i <= n; i++) scanf("%d", &target[i]);
			int ok = 1;
			while(B<=n) {
				//下面两行if和else if判断目标编号是否匹配栈顶元素
				//栈顶元素可以是当前的栈顶，也可以进栈元素压栈后成为新的栈顶 
				if(A==target[B]) 
					A++, B++;
				else if(!s.empty()&&s.top()==target[B])
					s.pop(), B++;
				//不匹配则可以进栈 
				else if(A<=n)
					s.push(A++);
				//若无元素进栈且又找不到目标编号说明编号顺序不合理 
				else {
					ok = 0;
					break;
				}
			}
			printf("%s\n", ok?"Yes":"No");
		}
		//注意格式 
		printf("\n");
	}
}
