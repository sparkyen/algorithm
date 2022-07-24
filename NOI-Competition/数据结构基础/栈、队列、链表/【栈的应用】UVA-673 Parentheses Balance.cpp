/* 
使用栈判断括号序列是否合理 
*/
#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
const int maxn = 1e5+100; 
int n;
char s[maxn];
int main(){
    cin >> n; 
	getchar();
    while(n--){
        stack<char> stk;
        gets(s);
        for(int i=0; i<strlen(s); i++){
            if(stk.empty()) stk.push(s[i]);
            else if(stk.top()=='('&&s[i]==')'||stk.top()=='['&&s[i]==']')
                stk.pop();
            else stk.push(s[i]);
        }
        if(stk.empty()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
