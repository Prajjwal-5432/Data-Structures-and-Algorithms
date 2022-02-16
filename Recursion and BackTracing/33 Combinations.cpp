//Link: https://nados.io/question/combinations-1?zen=true
#include<bits/stdc++.h>
using namespace std;

int n, k;
string s;
void combine(int placed, int pos) {
    if(placed == k) {
        cout << s << endl;
        return;
    }
    for(int i = pos + 1; i < n; ++i) {
        if(s[i] == '-') {
            s[i] = 'i';
            combine(placed + 1, i);
            s[i] = '-';
        }
    }
}

int main() {
    cin >> n >> k;

    s.resize(n, '-');
    combine(0, -1);
}