//Link: https://nados.io/question/word-break-i?zen=true
#include<bits/stdc++.h>
using namespace std;
unordered_set<string> st;

void go(string str, string asf) {
    if(str.empty()) {
        cout << asf << endl;
        return;
    }

    int i = 0;
    while(i < str.length()) {
        if(st.count(str.substr(0, i + 1))) {
            go(str.substr(i + 1), asf + str.substr(0, i + 1) + " ");
        }
        i++;
    }
}
int main() {
    int n;
    cin >> n;

    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        st.insert(s);
    }
    
    string str;
    cin >> str;

    go(str, "");
}