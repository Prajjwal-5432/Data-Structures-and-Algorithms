//Link: https://nados.io/question/words-k-selection-1?zen=true
#include <bits/stdc++.h>
using namespace std;

void combo(string asf, int idx, int placed, string s, int k) {
    if(idx == s.length()) {
        if(placed == k) cout << asf << endl;
        return;
    }
    combo(asf + s[idx], idx + 1, placed + 1, s, k);
    combo(asf, idx + 1, placed, s, k);
}

int main() {
    string s;
    int n;
    cin >> s >> n;

    string ustr;
    set<char> st;

    for(auto x: s) {
        if(!st.count(x)) {
            st.insert(x);
            ustr += x;
        }
    }

    combo("", 0, 0, ustr, n);
}