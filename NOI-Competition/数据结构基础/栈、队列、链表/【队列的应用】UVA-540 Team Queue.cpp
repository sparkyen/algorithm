/*
有 t 个小组排队，每个小组有若干人.
当一个人入队时，如果队伍中已有与他同一队伍的人，那么这个人就插到同一队伍人的最后，否则插到队伍最后.
先给出若干入队和出队指令，要求输出出队顺序.
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
                    q[0].push(team[x]); //q[0]队列用于记录排队的队伍编号 
                q[team[x]].push(x);
            }
            else if(s[0]=='D'){
            	int top = q[0].front(); //队列最前面的队伍编号 
                printf("%d\n", q[top].front());
                q[top].pop();
                if(q[top].empty()) q[0].pop();
            }
        }
        printf("\n");
    }
    return 0;
}

