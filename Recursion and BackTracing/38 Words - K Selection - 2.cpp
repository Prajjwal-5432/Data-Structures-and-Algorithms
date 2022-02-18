//Link: https://nados.io/question/words-k-selection-2?zen=true
#include<bits/stdc++.h>
using namespace std;
vector<char> ans;

void combo(int idx, string s) {
    if(idx == ans.size()) {
        for(auto x: ans) cout << x;
        cout << endl;
        return;
    }
    for(int i = 0; i < s.length(); ++i) {
        ans[idx] = s[i];
        combo(idx + 1, s.substr(i + 1));
    }
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

    ans.resize(n);
    combo(0, ustr);
}