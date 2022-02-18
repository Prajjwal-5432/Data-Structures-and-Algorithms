//Link: https://nados.io/question/words-k-length-words-2?zen=true
#include <bits/stdc++.h>
using namespace std;

void generateWords(string asf, int placed, int k, string s) {
    if(placed == k) {
        cout << asf << endl;
        return;
    }
    for(int i = 0; i < s.length(); ++i) {
        generateWords(asf + s[i], placed + 1, k, s.substr(0, i) + s.substr(i + 1));
    }
}

int main() {
    string str;
    int k;
    
    cin >> str >> k;
    set<char> unique;
    string ustr = "";
    for(int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if(unique.find(ch) == unique.end()) {
            unique.insert(ch);
            ustr += ch;
        }
    }

    generateWords("", 0, k, ustr);
    return 0;
}