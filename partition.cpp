#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dp[1010] = {0};
string origin;

bool valid(int lower, int upper){
    --lower; --upper;
    while(lower <= upper && origin[lower] == origin[upper]){
        ++lower; --upper;
    }
    return lower >= upper;
}

int main(){
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> origin;
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0; dp[1] = 1;
        for(int i = 1; i <= origin.size(); ++i){
            for(int j = 1; j <= i; ++j){
                if(valid(j, i))
                    dp[i] = min(dp[i],dp[j-1] + 1);
            }
        }
        cout << dp[origin.size()] << endl;
    }
    return 0;
}