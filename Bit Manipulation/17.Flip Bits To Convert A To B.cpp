//Link: https://nados.io/question/flip-bits-to-convert-a-to-b?zen=true
//after taking xor the bit position that differ will produce one

#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    // string s = bitset<50> (a).to_string();
    // string t = bitset<50> (b).to_string();

    // int cnt = 0;
    // for(int i = 0; i < s.length(); ++i) cnt += s[i] != t[i];

    // cout << cnt;

    cout << __builtin_popcountll(a ^ b);
}