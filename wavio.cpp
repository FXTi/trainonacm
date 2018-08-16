#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int a[10010] = {0};
int r[10010] = {0};
int instack[10010] = {0};
int destack[10010] = {0};
int x[10010] = {0};
int y[10010] = {0};

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int N, tmp;
    while(cin >> N && N){
        for(int i = 0, l = N - 1; i != N; ++i, --l){
            cin >> a[i];
            r[l] = a[i];
        }
        int inpos = 1;
        x[0] = 1;
        instack[0] = a[0];
        for(int i = 1; i != N; ++i){
            tmp = a[i];
            instack[(tmp > instack[inpos - 1]) ? inpos++ : lower_bound(instack, instack + inpos, tmp) - instack] = tmp;
            x[i] = inpos;
        }
        int depos = 1;
        y[N-1] = 1;
        destack[0] = r[0];
        for(int i = 1; i != N; ++i){
            tmp = r[i];
            destack[(tmp > destack[depos - 1]) ? depos++ : lower_bound(destack, destack + depos, tmp) - destack] = tmp;
            y[N-1-i] = depos;
        }
        int ans = 1;
        for(int i = 0; i != N; ++i)
            ans = max(ans, 2 * min(x[i], y[i]) - 1);
        cout << ans << endl;
    }
    return 0;
}