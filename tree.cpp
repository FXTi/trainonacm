#include <bits/stdc++.h>
using namespace std;
int N, X, Y, L;
long long ans;

struct Path{
	int t;
	int w;
	int next;
};

int pos;
const int maxn = 100010;
const int mod = 1000000000 + 7;
Path path[maxn];
int head[maxn] = {0};
int sum[maxn] = {0};

inline void add(int from, int to, int weight){
    path[pos].t = to;
    path[pos].w = weight;
    path[pos].next = head[from];
    head[from] = pos++;
}

void dfs(int root, int father){
    sum[root] = 1;
    int son;
    for(int i = head[root]; i != -1; i = path[i].next){
        son = path[i].t;
        if(son != father){
            dfs(son, root);
            sum[root] += sum[son];
            ans = (ans + ((sum[son] * (N - sum[son])) % mod) * path[i].w) % mod;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    while(cin >> N){
        ans = 0;
        pos = 0;
        for(int i = 1; i <= N; ++i)
            head[i] = -1;
        for(int i = 0; i != N-1; ++i){
            cin >> X >> Y >> L;
            add(X, Y, L);
            add(Y, X, L);
        }
        memset(sum, 0, sizeof(sum));
        dfs(1,-1);
        cout << ((4 * ans) % mod) << endl;
    }
    return 0;
}