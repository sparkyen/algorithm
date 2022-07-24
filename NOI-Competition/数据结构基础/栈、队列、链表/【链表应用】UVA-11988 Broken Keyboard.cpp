#include<cstdio> 
#include<cstring> 
const int maxn = 1e5+100; 
int last, cur, nxt[maxn]; 
char s[maxn];
int main() {
	while(~scanf("%s", s+1)) {
		int n = strlen(s+1); 
		last = cur = 0;
		nxt[0] = -1; //链表的头节点 
		// cur用于记录新节点插入链表的位置 
		for(int i = 1; i <= n; i++) {
			char ch = s[i];
			if(ch=='[') cur = 0;
			else if(ch==']') cur = last;
			//模拟链表插入操作 
			else {
				nxt[i] = nxt[cur]; //第一步 
				nxt[cur] = i; //第二步 
				if(cur==last) last = i; //若在尾部插入则更新尾id的标记 
				cur = i; //第三步(移动光标) 
			}
		} 
		//链表输出
		for(int i = nxt[0]; i != -1; i = nxt[i])
			printf( "%c", s[i] );
		printf( "\n" );
	}
}

