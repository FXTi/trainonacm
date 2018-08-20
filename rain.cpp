#include <bits/stdc++.h>
using namespace std;

int xp[1000010] = {0};
int yp[1000010] = {0};
int xc[1000010] = {0};
int yc[1000010] = {0};
double a[1000010];
double c[1000010];

int main(){
    int t, n, m, r;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d%d", &n, &m, &r);
        for(int i = 0;i != n; ++i)
            scanf("%d%d", &xp[i], &yp[i]);
        for(int i = 0;i != n; ++i)
            scanf("%d%d", &xc[i], &yc[i]);
        a[0] = (1.0*yp[0] - 1.0*yp[n-1]) / (1.0*xp[0] - 1.0*xp[n-1]);
        c[0] = a[0] * xp[0] + 1.0*yp[0];
        for(int i = 1; i != n; ++i){
            a[i] = (1.0*yp[i] - 1.0*yp[i-1]) / (1.0*xp[i] - 1.0*xp[i-1]);
            c[i] = a[i] * xp[i] + 1.0*yp[0];
        }
        for(int i = 0;i != m; ++i){
            
        }
    }
    return 0;
}