/*
�� t ��С���Ŷӣ�ÿ��С����������.
��һ�������ʱ�������������������ͬһ������ˣ���ô����˾Ͳ嵽ͬһ�����˵���󣬷���嵽�������.
�ȸ���������Ӻͳ���ָ�Ҫ���������˳��.
*/ 
#include<cstdio> 
#include<stack> 
#include<iostream> 
#include<string> 
#include <queue>
using namespace std;
const int maxn = 1e3+100;
char s[10];
int team[1000100];
int main(){
    int t, num, x, ca = 0;
    while(~scanf("%d", &t)&&t){
        printf("Scenario #%d\n", ++ca);
        queue<int> q[maxn];  
        for(int i = 1; i <= t; ++i){
            scanf("%d", &num);
            while(num--){
                scanf("%d", &x);
                team[x] = i;
            }
        }
        while(1){
            scanf("%s", s);
            if(s[0]=='S') break;
			else if(s[0]=='E'){
                scanf("%d", &x);
                if(q[team[x]].empty())
                    q[0].push(team[x]); //q[0]�������ڼ�¼�ŶӵĶ����� 
                q[team[x]].push(x);
            }
            else if(s[0]=='D'){
            	int top = q[0].front(); //������ǰ��Ķ����� 
                printf("%d\n", q[top].front());
                q[top].pop();
                if(q[top].empty()) q[0].pop();
            }
        }
        printf("\n");
    }
    return 0;
}

