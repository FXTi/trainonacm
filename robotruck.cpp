#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100000 + 10;

int x[maxn] = {0};
int y[maxn] = {0};
int total_dist[maxn] = {0};
int total_weight[maxn] = {0};
int dist2origin[maxn] = {0};
int q[maxn] = {0};
int d[maxn] = {0};

inline int func(int i){
    return d[i] - total_dist[i+1] + dist2origin[i+1];
}

int main(){
    int T, c, n, w, front, rear;
    cin >> T;
    while(T--){
        cin >> c >> n;
        for(int i = 1; i <= n; ++i){
            cin >> x[i] >> y[i] >> w;
            dist2origin[i] = abs(x[i]) + abs(y[i]);
            total_dist[i] = total_dist[i-1] + abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
            total_weight[i] = total_weight[i-1] + w;
        }
        front = rear = 1;
        for(int i = 1; i <= n; ++i){
            while(front <= rear && total_weight[i] - total_weight[q[front]] > c)
                ++front;
            d[i] = func(q[front]) + total_dist[i] + dist2origin[i];
            while(front <= rear && func(i) <= func(q[rear]))
                --rear;
            q[++rear] = i;
        }
        cout << d[n] << endl;
        if(T > 0)
            cout << endl;
    }
    return 0;
}