#include <iostream>
#include <list>
#include <string>
using namespace std;
list<char> l;
string str;
int main(){
    while(cin>>str){
        l.clear();
        list<char>::iterator it = l.begin();
        for(int i = 0; i < str.size(); i++){
            if(str[i]=='[') it = l.begin();
            else if(str[i]==']') it = l.end();
            else l.insert(it, str[i]);
        }
        for(it = l.begin(); it != l.end(); it++)
            cout << (*it);
        cout<<endl;
    }
}
/*
Sample Input
This_is_a_[Beiju]_text
[[]][][]Happy_Birthday_to_Tsinghua_University
This_is_a_[Beiju]_text[Xiao]1236
Sample Output
BeijuThis_is_a__text
Happy_Birthday_to_Tsinghua_University
XiaoBeijuThis_is_a__text1236 
*/ 
