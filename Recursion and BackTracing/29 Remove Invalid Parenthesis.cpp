//Link: https://nados.io/question/remove-invalid-parenthesis?zen=true
#include<bits/stdc++.h>
using namespace std;
unordered_set<string> st;
bool isBal(string str) {
    vector<char> v;
    for(int i = 0; i < str.length(); ++i) {
        if(str[i] == '(') v.push_back(str[i]);
        else {
            if(!v.empty() and v.back() == '(') v.pop_back();
            else return 0;
        }
    }

    return v.empty();
}

void go(string str, int mr) {
    if(mr == 0) {
        if(isBal(str) and !st.count(str)) {
            st.insert(str);
            cout << str << endl;
        }
        return;
    }

    for(int i = 0; i < str.length(); ++i) {
        if(i and str[i] == str[i - 1]) continue;
        go(str.substr(0, i) + str.substr(i + 1), mr - 1);
    }
}

int main() {
    string str;
    cin >> str;

    vector<char> v;

    for(int i = 0; i < str.length(); ++i) {
        if(str[i] == '(') v.push_back(str[i]);
        else {
            if(!v.empty() and v.back() == '(') v.pop_back();
            else v.push_back(str[i]);
        }
    }

    int mr = v.size();
    go(str, mr);
}