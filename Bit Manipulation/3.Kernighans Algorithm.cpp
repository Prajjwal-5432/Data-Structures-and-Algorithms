//Link: https://nados.io/question/kernighans-algorithm?zen=true

#include<bits/stdc++.h>
using namespace std;
int main() {
    int x;
    cin >> x;
    
    int cnt = 0;
    while(x) {
        x -= (x & -x);
        cnt++;
    }

    cout << cnt;
    // cout << __builtin_popcount(x);
}