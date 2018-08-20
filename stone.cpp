#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
        long long tmp;
        while(b>0){
            tmp = a;
            a = b;
            b = tmp % b;
        }
        return a;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    int a, b, c;
    int a1, b1, c1;
    long long ans, n;
    bool positive;
    cin >> t;
    while(t--){
        positive = true;
        cin >> a >> b >> c;
        cin >> a1 >> b1 >> c1;
        ans = (long long)a*b1 - (long long)b*a1 + (long long)b*c1 - (long long)c*b1 + (long long)c*a1 - (long long)a*c1;
        n = a + b + c;
        if(ans){
            if(ans < 0){
                positive = false;
                ans = -ans;
            }
            if(ans % n){
                long long G = gcd(ans,n);
                ans /= G;
                n /= G;
                if(!positive)
                    ans = -ans;
                cout << ans << "/" << n << endl;
            }else{
                if(!positive)
                    ans = -ans;
                cout << ans / n << endl;
            }
        }
        else{
            cout << "0" << endl;
        }
    }
    return 0;
}