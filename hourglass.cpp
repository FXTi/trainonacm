#include<cstdio>
#include<cstring>
#include <algorithm>
using namespace std;
 
const int INF = 0x3f3f3f3f;
const int N = 105;
 
int s, n, m;
int f[N][1 << 17];
int cost[N], sta[N];
 
int changesta(int st, int x) {
	for(int i = 0; i < 2 * s; i += 2)
		if(x & (1 << i)) {
			int st1 = 1 << i;
			int st2 = 1 << (i + 1);
 
			if(st & st2) {
				st -= st2;
				continue;
			}
			if(st & st1) {
				st -= st1;
				continue;
			}
		}
	return st;
}
 
int dp(int n, int t) {
	if(t == 0)
		return 0;
	if(n == 0)
		return INF - 1;
	if(f[n][t] < INF)
		return f[n][t];
	return f[n][t] = min(f[n][t], min(dp(n - 1, t), dp(n - 1, changesta(t, sta[n])) + cost[n]));
}
 
int main() {
	while(scanf("%d%d%d",&s,&m,&n) && s) {
		int temp, sum = 0;
		int	t = (1 << (2 * s)) - 1;
		char ch;
		for(int i = 0; i < m; i++) {
			scanf("%d%c", &temp, &ch);
			sum += temp;
			while(ch != '\n') {
				scanf("%d%c", &temp, &ch);
				int t1 = 1 << (2 * temp - 1);
				int t2 = 1 << (2 * temp - 2);
				if(t & t1) {
					t -= t1;
					continue;
				}
				if(t & t2) {
					t -= t2;
					continue;
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			scanf("%d%c", &temp, &ch);
			cost[i] = temp;
			sta[i] = 0;
			while(ch != '\n') {
				scanf("%d%c", &temp, &ch);
				int temp2 = 1 << (2 * temp - 2);
				sta[i] |= temp2;
			}
		}
		memset(f,INF,sizeof(f));
		printf("%d\n", dp(n, t) + sum);
	}
	return 0;
}