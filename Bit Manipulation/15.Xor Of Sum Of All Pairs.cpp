//Link: https://nados.io/question/xor-of-sum-of-all-pairs?zen=true
// most of the pairs will kill itself only the the pair of a num with itself with remain

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long val = 0;
    for(int i = 0, x; i < n; ++i) {
        cin >> x;

        val ^= (x << 1);
    }

    cout << val;
}