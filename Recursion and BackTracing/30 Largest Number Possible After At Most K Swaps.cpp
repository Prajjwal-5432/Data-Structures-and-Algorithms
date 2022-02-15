//Link: https://nados.io/question/remove-invalid-parenthesis?zen=true
#include<bits/stdc++.h>
using namespace std;
string mx;
void go(string str, int swaps) {
    if(str > mx) {
        mx = str;
    }

    if(swaps == 0) return;

    for(int i = 0; i < str.length(); ++i) {
        for(int j = i + 1; j < str.length(); ++j) {
            if(str[i] < str[j]) {
                swap(str[i], str[j]);
                go(str, swaps - 1);
                swap(str[i], str[j]);
            }
        }
    }
}

int main() {
    int swaps;
    string str;
    cin >> str >> swaps;

    mx = str;

    go(str, swaps);
    cout << mx;
}