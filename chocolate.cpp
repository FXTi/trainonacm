#include <iostream>
#include <cstring>
using namespace std;

const int maxn = 1 << 16;
const int maxw = 100 + 10;
int part[20] = {0};
int f[maxw][maxn] = {0};
int vis[maxw][maxn] = {0};
int total[maxn] = {0};

int dp(int x, int G){
    if(vis[x][G])
        return f[x][G];
    vis[x][G] = 1;
    int &ans = f[x][G];
    if(!((G - 1) & G)) 
        return ans = 1;
    int y = total[G]  / x;
    for(int S0 = (G - 1) & G; S0; S0 = (S0 - 1) & G){
        int S1 = G - S0;
        if(total[S0] % x == 0 && dp(min(x, total[S0] / x), S0) && dp(min(x, total[S1] / x), S1))
            return ans = 1;
        if(total[S0] % y == 0 && dp(min(y, total[S0] / y), S0) && dp(min(y, total[S1] / y), S1))
            return ans = 1;
    }
    return ans = 0;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int n, x, y, T = 0;
    while(cin >> n && n){
        cin >> x >> y;
        for(int i = 0; i != n; ++i)
            cin >> part[i];
        memset(total, 0, sizeof(total));
        for(int S = 0; S < (1 << n); ++S)
            for(int i = 0; i != n; ++i)
                if(S & (1 << i))
                    total[S] += part[i]; 
        memset(vis, 0, sizeof(vis));
        const int all = (1 << n) - 1;
        int ans;
        if(total[all] != x * y || total[all] % x != 0)
            ans = 0;
        else  
            ans = dp(min(x, y), all);
        cout << "Case " << ++T << ": " << (ans ? "Yes" : "No") << endl;
    }
    return 0;
}