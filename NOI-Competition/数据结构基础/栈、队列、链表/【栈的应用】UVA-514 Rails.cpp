/*
Ŀ�����пɰ��ս�ջ˳��1~n��ջ�γɣ����ж�Ŀ�������Ƿ���� 
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
			//ע������ϸ�� 
			scanf("%d", &target[1]);
			if(target[1]==0) break;
			for(int i = 2; i <= n; i++) scanf("%d", &target[i]);
			int ok = 1;
			while(B<=n) {
				//��������if��else if�ж�Ŀ�����Ƿ�ƥ��ջ��Ԫ��
				//ջ��Ԫ�ؿ����ǵ�ǰ��ջ����Ҳ���Խ�ջԪ��ѹջ���Ϊ�µ�ջ�� 
				if(A==target[B]) 
					A++, B++;
				else if(!s.empty()&&s.top()==target[B])
					s.pop(), B++;
				//��ƥ������Խ�ջ 
				else if(A<=n)
					s.push(A++);
				//����Ԫ�ؽ�ջ�����Ҳ���Ŀ����˵�����˳�򲻺��� 
				else {
					ok = 0;
					break;
				}
			}
			printf("%s\n", ok?"Yes":"No");
		}
		//ע���ʽ 
		printf("\n");
	}
}
