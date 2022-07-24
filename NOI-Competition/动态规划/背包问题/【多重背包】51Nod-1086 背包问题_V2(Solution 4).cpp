/*
��ϱ�������   ref: https://www.cnblogs.com/Draymonder/p/7358254.html
AC: 46ms / ���������ʱ���� 78ms (��ѧ)
*/ 
#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int dp[50100];
int main (){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
    	int w, v, c;
    	cin >> w >> v >> c;
        if(w*c > m){ //���  ����*���� >= ��������������ȫ����
            for(int j = w;j <= m;j++)
                dp[j] = max(dp[j], dp[j-w]+v);
        }
        else{ //����  ����01����������д��
            int k = 1;
            while (k<c){
            	//���ʱ���ǾͿ��԰���01�������
                for(int j = m;j >= w*k; j--)
                    dp[j] = max(dp[j], dp[j-w*k]+k*v);
                c -= k, k *= 2;
            }
            for(int j = m;j >= w*c; j--)
                dp[j] = max(dp[j],dp[j-w*c]+c*v);
        }
    }
    cout << dp[m];
}
