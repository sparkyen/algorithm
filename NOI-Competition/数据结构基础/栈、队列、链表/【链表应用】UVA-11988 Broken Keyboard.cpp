#include<cstdio> 
#include<cstring> 
const int maxn = 1e5+100; 
int last, cur, nxt[maxn]; 
char s[maxn];
int main() {
	while(~scanf("%s", s+1)) {
		int n = strlen(s+1); 
		last = cur = 0;
		nxt[0] = -1; //�����ͷ�ڵ� 
		// cur���ڼ�¼�½ڵ���������λ�� 
		for(int i = 1; i <= n; i++) {
			char ch = s[i];
			if(ch=='[') cur = 0;
			else if(ch==']') cur = last;
			//ģ������������ 
			else {
				nxt[i] = nxt[cur]; //��һ�� 
				nxt[cur] = i; //�ڶ��� 
				if(cur==last) last = i; //����β�����������βid�ı�� 
				cur = i; //������(�ƶ����) 
			}
		} 
		//�������
		for(int i = nxt[0]; i != -1; i = nxt[i])
			printf( "%c", s[i] );
		printf( "\n" );
	}
}

