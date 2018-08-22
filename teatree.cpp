#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, tmp;

int pre[maxn] = {0};
int size[maxn] = {0};

vector<int> nedge[maxn];
int val[maxn] = {0};
int ans[maxn] = {0};

int vis[maxn] = {0};
int fa[maxn] = {0};

int find(int x){
    while(pre[x] != x){
        pre[x] = pre[pre[x]];
        x = pre[x];
    }
    return x;
}

void uni(int a, int b){
    int l = find(a);
    int r = find(b);
    if(l == r)
        return ;
    if(size[l] < size[r])
        pre[l] = r;
    else{
        pre[r] = l;
        if(size[l] == size[r])
            ++size[l];
    }
}

void lca(int u){
    for(auto p = nedge[u].cbegin(); p != nedge[u].cend(); ++p){
        int v = *p;
        lca(v);
        uni(u, v);
        fa[find(u)] = u;
    }
    vis[u] = 1;
    for(int v = 1; v <= n; ++v){
        if(v == u)
            continue;
        if(vis[v]){
            int &t = ans[fa[find(v)]];
            t = max(t, __gcd(val[u], val[v]));
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 2; i <= n; ++i){
        cin >> tmp;
        nedge[tmp].push_back(i);
    }
    for(int i = 1; i <= n; ++i){
        pre[i] = i;
        cin >> val[i];
        ans[i] = -1;
    }
    lca(1);
    for(int i = 1; i <= n; ++i)
        cout << ans[i] << endl;
    return 0;
}