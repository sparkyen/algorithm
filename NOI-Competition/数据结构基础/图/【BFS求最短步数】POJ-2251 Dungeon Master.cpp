#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <queue>
using namespace std;
int l, r, c, sx, sy, sz;
bool vis[105][105][105];
char mp[105][105][105];
struct node{
    int x, y, z;
	int step;
	node(int x, int y, int z, int step): x(x), y(y), z(z), step(step) {}
};
int mv[6][3]={{0,0,1},{0,0,-1},{1,0,0},{-1,0,0},{0,1,0},{0,-1,0}};
void bfs(){
    queue<node> que;
    vis[sx][sy][sz] = 1;
    que.push(node(sx, sy, sz, 0));
    while(!que.empty()){
        node now = que.front(); que.pop();
        if(mp[now.x][now.y][now.z]=='E'){
			printf("Escaped in %d minute(s).\n", now.step);
			return ;
        }
        for(int i = 0; i < 6; i++){
        	int nx = now.x+mv[i][0], ny = now.y+mv[i][1], nz = now.z+mv[i][2];
            if(0<=nx&&nx<l&&0<=ny&&ny<r&&0<=nz&&nz<c&&!vis[nx][ny][nz]&&mp[nx][ny][nz]!='#'){
                vis[nx][ny][nz] = 1;
                que.push(node(nx, ny, nz, now.step+1));
            }
        }
    }
    puts("Trapped!");
}
int main(){
    while(~scanf("%d%d%d", &l, &r, &c)){
    	if(!l&&!r&&!c) break;
        for(int i = 0; i < l; i++)
            for(int j = 0; j < r; j++){
            	scanf("%s", mp[i][j]);
            	for(int k = 0; k < c; k++){
            		vis[i][j][k] = 0;
            		if(mp[i][j][k]=='S')
						sx = i, sy = j, sz = k;
				}	
			}
        bfs();
    }
}
