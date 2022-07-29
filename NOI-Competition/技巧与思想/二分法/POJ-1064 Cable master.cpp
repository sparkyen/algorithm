#include <cstdio>
#include <cmath>
int n, k;
const int maxn = 1e3+100;
double a[maxn];
bool judge(double len) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += a[i] / len;
    return cnt >= k;
}
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%lf", a + i);
    double l = 0, r = 1e4+100;
    for (int i = 0; i < 100; i++){
        double mid = (l + r) / 2;
        if (judge(mid)) l = mid;
        else r = mid;
    }
    
    printf("%.2lf\n", floor(l * 100) / 100);
}
