#include <bits/stdc++.h>
using namespace std;

int m[500050] = {0};
int Max[250020] = {0};
typedef pair<int, int> Use;

Use use[250020];

const int mod = 1e9+7;

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        int ans = 0, local = 0;
        for(int i = 1; i <= n; ++i){
            scanf("%d", &m[i]);
            use[i].first = m[i] - i;
            use[i].second = i;
        }
        Max[n] = m[n] - n;
        for(int i = n-1; i >= 1; --i)
            Max[i] = max(Max[i+1], m[i]-i);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &m[500049]);
        sort(use + 1, use + n + 1, greater<Use>());
        for(int i = 1; i <= n; ++i){
            m[n + i] = max(use[i].first, Max[use[i].second]);
            m[n + i] = max(m[n + i], local);
            local = max(local, m[n+i] - (n+i));
            ans = (ans + m[n+i]) % mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}