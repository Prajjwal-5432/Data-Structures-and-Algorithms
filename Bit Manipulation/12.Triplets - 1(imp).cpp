//Link: https://nados.io/question/triplets-1?zen=true

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> ar(n);
    for(auto &x: ar) cin >> x;

    int cnt = 0;
    for(int i = 0; i < n; ++i) {
        int val = ar[i];
        for(int k = i + 1; k < n; ++k) {
            val ^= ar[k];

            if(val == 0) cnt += k - i;
        }
    }

    cout << cnt;
}