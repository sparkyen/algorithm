#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n;
int f[110][110];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> f[i][j];
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] |= f[i][k] & f[k][j];
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            cout << f[i][j] << ' ';
        cout << endl;
    }
}
