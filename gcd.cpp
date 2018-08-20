#include <bits/stdc++.h>
using namespace std;

int main(){
    int T, G, L, sum;
    cin >> T;
    while(T--){
        cin >> G >> L;
        if(L % G)
            cout << -1 << endl;
        else
            cout << G << " " << L << endl;
    }
    return 0;
}