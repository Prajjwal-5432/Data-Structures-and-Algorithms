//Link: https://nados.io/question/words-k-length-words-3?zen=true
#include<bits/stdc++.h>
using namespace std;
string s;
int k;
unordered_map<char, int> pos;
vector<char> v;
void permute(int idx, int placed) {
    if(idx == s.length()) {
        if(placed == k) {
            for(auto x: v) cout << x;
            cout << endl;
        }
        return;
    }

    int val = pos[s[idx]];
    for(int i = pos[s[idx]] + 1; i < k; ++i) {
        if(v[i] == '-') {
            pos[s[idx]] = i;
            v[i] = s[idx];
            permute(idx + 1, placed + 1);
            v[i] = '-';
            pos[s[idx]] = val;
        }
    }

    if(val == -1) permute(idx + 1, placed);
}

int main() {
    cin >> s >> k;
    for(auto x: s) pos[x] = -1;
    v.resize(k, '-');
    permute(0, 0);
}