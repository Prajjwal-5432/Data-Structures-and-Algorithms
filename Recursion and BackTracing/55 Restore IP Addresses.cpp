//Link: https://nados.io/question/restore-ip-addresses?zen=true
#include<bits/stdc++.h>
using namespace std;
string s;
vector<string> v;
vector<string> ans;
void restore(int idx) {
    if(v.size() == 3) {
        string t = s.substr(idx);
        if(t.length() == 0) return;
        if(t.length() > 1 and t[0] == '0') return;
        if(stoll(t) >= 0 and stoll(t) <= 255) {
            string st;
            for(auto x: v) st += x + ".";
            st += t;
            ans.push_back(st);
        }
        return;
    }
    if(s[idx] == '0') {
        v.push_back(s.substr(idx, 1));
        restore(idx + 1);
        v.pop_back();
    } else {
        for(int i = idx; i < idx + 3 and i < s.length(); i++) {
            string t = s.substr(idx, i - idx + 1);
            if(stoll(t) > 0 and stoll(t) <= 255) {
                v.push_back(t);
                restore(i + 1);
                v.pop_back();
            }
        }
    }
}
int main() {
    cin >> s;

    if(s.length() < 3 or s.length() > 12) return cout << "[]", 0;

    restore(0);

    cout << "[";
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i == ans.size() - 1 ? "" : ", ");
    }
    cout << "]";
}