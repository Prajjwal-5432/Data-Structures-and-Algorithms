//Link: https://nados.io/question/permutations-words-1?zen=true
#include<bits/stdc++.h>
using namespace std;

map<char, int> mp;
string s;

void go(string asf) {
    if(s.length() == asf.length()) {
        cout << asf << endl;
        return;
    }
    for(auto& x: mp) {
        if(x.second) {
            x.second--;
            go(asf + x.first);
            x.second++;
        }
    }
}

int main() {
    cin >> s;
    for(auto x: s) mp[x]++;
    go("");
}