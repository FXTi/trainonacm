#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
 
struct node {
	int len;
	string str;
}dp[1010][1010];
char s1[1010], s2[1010];
int main() {
	while(scanf("%s", s1+1) == 1) {
		int n = strlen(s1 + 1);
		strcpy(s2+1, s1+1);
		reverse(s2+1, s2+1+n);
		for(int i=0; i<=n; i++)
		  for(int j=0; j<=n; j++) {
		  	 dp[i][j].len = 0;
		  	 dp[i][j].str = "";
		  }
		for(int i=1; i<=n; i++)
		  for(int j=1; j<=n; j++) {
		  	 if(s1[i] == s2[j]) {
		  	 	 dp[i][j].len = dp[i-1][j-1].len + 1;
		  	 	 dp[i][j].str = dp[i-1][j-1].str + s1[i];
		  	 }
		  	 else if(dp[i-1][j].len > dp[i][j-1].len) {
		  	 	 dp[i][j].len = dp[i-1][j].len;
		  	 	 dp[i][j].str = dp[i-1][j].str;
		  	 }
		  	 else if(dp[i][j-1].len > dp[i-1][j].len) {
		  	 	 dp[i][j].len = dp[i][j-1].len;
		  	 	 dp[i][j].str = dp[i][j-1].str;
		  	 }
		  	 else {
		  	 	  dp[i][j].len = dp[i-1][j].len;
		  	 	  dp[i][j].str = min(dp[i][j-1].str, dp[i-1][j].str);
		  	 }
		  }
        string s = dp[n][n].str;
        int l = dp[n][n].len;
        if(l & 1) {
            for(int i=0; i<(l-1)/2; i++)
                cout << s[i];
            for(int i=(l-1)/2; i>=0; i--)
                cout << s[i];
        }
        else {
            for(int i=0; i < l; i++)
                cout << s[i];
        }
        cout << endl;
	}
	return 0;
}