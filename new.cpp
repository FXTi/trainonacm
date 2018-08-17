#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

const long long mod = 4294967296;

long long sum[3010][3010] = {0};
int n, m, q;

unsigned int A,B,C;
inline unsigned int rng61(){
    A ^= A << 16;
    A ^= A >> 5;
    A ^= A << 1;
    unsigned int t = A;
    A = B;
    B = C;
    C ^= t ^ A;
    return C;
}

int main(){
    scanf("%d%d%d%u%u%u", &n, &m, &q, &A, &B, &C);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            sum[i][j] = (rng61() + sum[i][j-1]) % mod;
        }
    }
    unsigned int x, y, k;
    long long ans = 0;
    for(int i = 1; i <= q; i++){
        long long tmp = 0;
        x = rng61() % n + 1;
        y = rng61() % m + 1;
        k = rng61() % min(x, y) + 1;
        for(int u = 1; u <= k; ++u)
            tmp = (tmp + sum[x - u + 1][y] - sum[x - u + 1][y - k + u - 1]) % mod;
        ans = ans * 233 % mod + tmp % mod;
        ans %= mod;
    }
    printf("%lld\n", ans);
    return 0;
}