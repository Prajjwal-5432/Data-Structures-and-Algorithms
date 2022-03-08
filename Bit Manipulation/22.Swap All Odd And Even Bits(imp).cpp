//Link: https://nados.io/question/swap-all-odd-and-even-bits?zen=true

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, a;
    cin >> n;
    a = n;

    for(int i = 0; i < 64; i += 2) {
        int emsk = (1 << i);
        int omsk = (1 << (i + 1));
        
        if((n & emsk) == 0) {
            a = a & (~omsk);
        } else {
            a = a | omsk;
        }
        if((n & omsk) == 0) {
            a = a & (~emsk);
        } else {
            a = a | emsk;
        }
    }

    cout << a;
}