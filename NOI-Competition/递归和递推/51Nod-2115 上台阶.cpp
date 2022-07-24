#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
const int maxn = 1e5+100, mod = 100003;
int n, f[maxn];
int main() { 
    cin >> n;
    f[1]=1, f[2]=2;
    for(int i = 3;i <= n;i++)
        f[i] = (f[i-1]%mod+f[i-2]%mod)%mod;
    cout << f[n];
}

