//Link: https://nados.io/question/number-of-valid-words?zen=true

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bitset<26>> puzzle(n, 0);
    
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for(auto x: s) puzzle[i][x - 'a'] = 1;
    }

    int m;
    cin >> m;

    for(int i = 0; i < m; ++i) {
        string s;
        cin >> s;

        bitset<26> word;
        for(auto x: s) word[x - 'a'] = 1;

        int cnt = 0;
        for(auto x: puzzle) {
            cnt += (x[s[0] - 'a'] == 1 and (word & x) == x);
        }

        cout << s << " -> " << cnt << endl;
    }

}