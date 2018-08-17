#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int mod = 1e9 + 7;

int m[50000] = {0};

int main(){
    for(int i = 2; i <= 50000; ++i)
        m[i] = (2+i)*(i-1)/2;
    for(int i = 2; i <= 10; ++i)
        cout << i << " " << m[i] << endl;
    int T, x, n, left, ans;
    scanf("%d", &T);
    while(T--){
        ans = 1;
        scanf("%d", &x);
        if(x < 5){
            printf("%d\n", x);
            continue;
        }
        int lower = 1, upper = 50000, mid;
        while(upper - lower > 1){
            mid = (lower + upper) / 2;
            if(m[mid] > x)
                upper = mid;
            else
                lower = mid;
        }
        n = lower;
        cout << "n " << n << endl;
        left = x - m[n];
        for(int i = n; i >= 2; --i){
            if(left-- > 0)
                ans = (ans * (i+1)) % mod;
            else
                ans = (ans * i) % mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}