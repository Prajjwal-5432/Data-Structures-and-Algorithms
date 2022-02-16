//Link: https://nados.io/question/permutations-words-2?zen=true
#include<bits/stdc++.h>
using namespace std;

string str, s;
vector<int> pos;

void permute(int idx) {
    if(idx == str.length()) {
        cout << s << endl;
        return;
    }
    for(int i = pos[str[idx] - 'a'] + 1; i < str.length(); ++i) {
        if(s[i] == '-') {
            int val = pos[str[idx] - 'a'];
            pos[str[idx] - 'a'] = i;
            s[i] = str[idx];
            permute(idx + 1);
            s[i] = '-';
            pos[str[idx] - 'a'] = val;
        }
    }
}

int main() {
    cin >> str;
    s.resize(str.length(), '-');
    pos.resize(26, -1);
    permute(0);
}