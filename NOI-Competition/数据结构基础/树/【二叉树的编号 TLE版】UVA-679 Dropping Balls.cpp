/*
�ⷨ��ȷ������ʱ�临�Ӷ�Ϊ O(t*I*D)��ԼΪ t*20*5e4 
ref: 
https://zhuanlan.zhihu.com/p/506722228
https://www.cnblogs.com/zhengbin/p/4345515.html
*/ 
#include<cstdio> 
#include<cstring> 
const int maxd = 20; 
int s[1<<maxd]; //��������Ϊ2maxd-1 
int main() {
	int t, D, I;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &D, &I);
		memset(s, 0, sizeof(s)); //���س�ʼΪ�ر� 
		int k, n = ( 1 << D ) - 1; //n���������
		for(int i = 0; i < I; i++) {
			k = 1;
			while(1){
				s[k] = !s[k];
				k = s[k] ? k*2 : k*2 + 1; //���ݿ���״̬ѡ�����䷽��
				if(k>n) break; //�Ѿ���"����"��
			}   //������I��С������  
		} 
		printf("%d\n", k/2); // "����"֮ǰ��Ҷ�ӱ��	
	}
}
