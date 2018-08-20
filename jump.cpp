#include <bits/stdc++.h>
using  namespace std;

int main(){
    int T;
    cin >> T;
    int n, m;
    int ans;
    while(T--){
        cin >> n >> m;
        ans = (m - 1) % 3;
        for(int i = 4; i <= n; ++i)
            ans = (ans + m) % i;
        cout << ans + 1 << " ";
        ans = (m - 1) % 2;
        for(int i = 3; i <= n; ++i)
            ans = (ans + m) % i;
        cout << ans + 1 << " ";
        ans = 0;
        for(int i = 2; i <= n; ++i)
            ans = (ans + m) % i;
        cout << ans + 1 << endl;
    }
    return 0;
}