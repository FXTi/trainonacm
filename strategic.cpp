#include <bits/stdc++.h>
using namespace std;

vector<int> edge[1500];
int vis[1500] = {0};
int dp[1500] = {0};

void dfs(int x){
    int tmp;
    vis[x] = 1;
    dp[x][0] = 0;
    dp[x][1] = 1;
    for(int i = 0; i != edge[x]; ++i){
        tmp = edge[x][i];
        if(vis[tmp])
            continue;
        dfs(tmp);
        dp[x][0] += dp[tmp][1];
        dp[x][1] += min(dp[tmp][0], dp[tmp][1]);
    }
}

int main(){
    int n;
    int nth, num, to;
    char x, y, z;
    while(scanf("%d", &n) != EOF && n){
        for(int i = 0; i != n; ++i)
            edge[i].clear();
        for(int i = 0; i != n; ++i){
            scanf("%d%c%c%d%c%d%c", &nth, &z, &y, &num, &x, &to)
            edge[nth].push_back(to);
            edge[to].push_back(nth);
            --num;
            while(num--){
                scand("%d", to);
                edge[nth].push_back(to);
                edge[to].push_back(nth);
            }
        }
        memset(vis, 0, sizeof(vis));
        dfs(0);
        printf("%d\n", min(dp[0][0], dp[0][1]));
    }
    return 0;
}