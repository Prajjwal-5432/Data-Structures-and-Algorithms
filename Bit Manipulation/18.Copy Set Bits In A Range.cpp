//Link: https://nados.io/question/copy-set-bits-in-a-range?zen=true

#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int l, r;
    cin >> l >> r;
    l--, r--;

    for(int i = l; i < r + 1; ++i) b |= (a & (1 << i));

    cout << b;
}