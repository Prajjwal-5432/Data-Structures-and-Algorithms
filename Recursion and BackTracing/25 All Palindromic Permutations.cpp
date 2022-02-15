//Link: https://nados.io/question/all-palindromic-permutations?zen=true
#include<bits/stdc++.h>
using namespace std;

map<char, int> mp;
char c;

void permute(string s, string asf) {
    if(s.empty()) {
        cout << asf;
        if(c != '.') cout << c;
        reverse(asf.begin(), asf.end());
        cout << asf << "\n";
        return;
    }

    for(int i = 0; i < s.length(); ++i) {
        if(i and s[i] == s[i - 1]) continue;
        permute(s.substr(0, i) + s.substr(i + 1), asf + s[i]);
    }
}
int main() {
    string s;
    cin >> s;

    c = '.';
    for(auto x: s) mp[x]++;

    s.clear();

    int odd = 0;
    for(auto &x: mp) {
        if(x.second & 1) {
            odd++;
            c = x.first;
        }
        x.second /= 2;
        s += string(x.second, x.first);
    }
    if(odd > 1) return cout << "-1", 0;

    permute(s, "");
}