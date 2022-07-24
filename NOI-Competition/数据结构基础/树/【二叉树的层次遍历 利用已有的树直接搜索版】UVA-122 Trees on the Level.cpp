/*
二叉树的层次遍历 
ref:
https://gist.github.com/OmarSRehan/eebe2ab5659324bf7052189d8adb7633
*/
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <map> 
#include <queue>
using namespace std;
map<string,int> mp;
/*
类似把第i个节点的左右子树信息存到tree[2*i]和tree[2*i+1]中
这里把名称为str节点的信息存到mp[str+"L"]和mp[str+"R"]中 
*/
int cnt, res[310];
//层次遍历 
void bfs(string root){
    queue<string> q;
    q.push(root);
    while(!q.empty()) {
		string cur = q.front(); q.pop();
		//若找到对应的结点则将其子节点放入队列 
		//(3, L), (4, R)
        if (mp.find(cur)!= mp.end()){
        	res[++cnt] = mp[cur];
            q.push(cur+"L");
            q.push(cur+"R");
        }
	}
}

int main(){
    string s;
    while(cin>>s){
        if(s!="()"){ //(11, LL)
            int i = 1;
            string r, t = "";
            while(s[i]!=',') t += s[i], i++;
            r = s.substr(i+1, s.length()-i-2);
            if(mp.find(r)==mp.end()) mp[r] = stoi(t);
            else mp["X"] = 0; //标记一个节点被多次赋予一个值
        } 
		else {
			cnt = 0, bfs("");
            if(cnt==mp.size()){
            	cout << res[1];
            	for(int i = 2; i <= cnt; i++)
            		cout << " " << res[i];
            } 
			else cout << "not complete";
            cout << endl;
            mp.clear();
        }
    }
    return 0;
}
/*
Sample Input
(11,LL) (7,LLL) (8,R)
(5,) (4,L) (13,RL) (2,LLR) (1,RRR) (4,RR) ()
(3,L) (4,R) ()
Sample Output
5 4 8 11 13 4 7 2 1
not complete
*/
