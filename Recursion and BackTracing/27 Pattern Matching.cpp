//Link: https://nados.io/question/pattern-matching?zen=true
#include<bits/stdc++.h>
using namespace std;

string ptr;

void go(string str, int idx, unordered_map<char, string> mp) {
    if(idx == ptr.length()) {
        if(str.empty()) {
            vector<int> v(26, 0);
            for(auto x: ptr) {
                if(!v[x - 'a']) {
                    cout << x << " -> " << mp[x] << ", ";
                }
                v[x - 'a'] = 1;
            }
            cout << "." << endl;
        }
        return;
    }

    if(mp.count(ptr[idx])) {
        if(str.length() >= mp[ptr[idx]].length()) {
            int len = mp[ptr[idx]].length();
            if(mp[ptr[idx]] == str.substr(0, len)) go(str.substr(len), idx + 1, mp);
        } else {
            return;
        }
    } else {
        int i = 0;
        while(i < str.length()) {
            mp[ptr[idx]] = str.substr(0, i + 1);
            go(str.substr(i + 1), idx + 1, mp);
            mp.erase(ptr[idx]);
            i++;
        }
    }
}

int main() {
    string str;
    cin >> str >> ptr;

    go(str, 0, unordered_map<char, string> ());
}