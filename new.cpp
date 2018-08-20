#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

struct Node{
    int child;
    int brother;
    int cnt;
    char c;
};

Node node[15000000];

int pos;

void add(const string &s){
    int sp = 0, np = 0;
    bool build = false;
    while(sp < s.size()){
        if(build){
            while(sp < s.size()){
                node[pos].c = s[sp];
                node[pos].cnt = 1;
                node[np].child = pos;
                np = pos++;
                ++sp;
            }
        } else {
        if(node[np].c == s[sp]){
            ++node[np].cnt;
            if(node[np].child)
                np = node[np].child;
            else
                build = true;
        } else {
            while(node[np].brother && node[np].c != s[sp])
                np = node[np].brother;
            if(node[np].c == s[sp]){
                ++node[np].cnt;
                if(node[np].child)
                    np = node[np].child;
                else
                    build = true;
            } else {
                node[pos].c = s[sp];
                node[pos].cnt = 1;
                node[np].brother = pos;
                np = pos++;
                build = true;
            }
        }
        ++sp;
        }
    }
}

int search(){
    int cnt = 0;
    for(int np = node[0].brother; np; np = node[np].brother){
        if(node[np].cnt <= 5)
            ++cnt;
        else {
        queue<int> Q;
        Q.push(node[np].child);
        while(!Q.empty()){
            int i = Q.front(); Q.pop();
            for(; i; i = node[i].brother){
                if(node[i].cnt <= 5){
                    ++cnt;
                } else
                    Q.push(node[i].child);
            }
        }
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T, n;
    string s;
    cin >> T;
    while(T--){
        memset(node, 0, sizeof(node));
        pos = 1;
        node[0].c = 'A';
        node[0].cnt = 1;
        cin >> n;
        while(n--){
            cin >> s;
            add(s);
        }
        cout << search() << endl;
    }
    return 0;
}