#include <iostream>
using namespace std;
#include <cstring>
#include <stdio.h>

char str[1005];
const int INF =0x3f3f3f3f;
int dp[1010][1010];
bool vis[130];

int main() {
    int T;
    int k;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&k);
        scanf("%s",str);
        int len = strlen(str);
        memset(dp,INF,sizeof(dp));
        for(int i = 0 ; i < len/ k; i++) {
            int chunks = 0;
            memset(vis,0,sizeof(vis));
            for(int j = i * k; j <=(i+ 1)*k - 1; j++) 
                           vis[str[j]] = true;
            for(int j = 'a'; j <= 'z'; j++)
                if(vis[j])
                     ++chunks;
            if(i == 0) {
                for(int j = 0; j <k ;j++)
                    dp[i][j] = chunks;
                continue;
            }
                for(int j = 0; j < k; j++) {
                    int rear = i * k + j;
                    for(int p = 0; p < k; p++) {
                        int pre = (i-1) * k + p;
                        if(vis[str[pre]] && (chunks == 1 || str[pre] != str[rear]))
                            dp[i][j] = min(dp[i][j],dp[i - 1][p] + chunks - 1);
                        else
                            dp[i][j] = min(dp[i][j],dp[i - 1][p] + chunks);
                    }
                }
        }
        int ans = INF;
        for(int i = 0; i < k; i ++) {
            ans = min(ans,dp[len / k - 1][i]);
        }
        printf("%d\n",ans);
    }
    return 0;
}