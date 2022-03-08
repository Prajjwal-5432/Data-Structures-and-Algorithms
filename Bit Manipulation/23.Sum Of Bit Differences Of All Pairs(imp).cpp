//Link: https://nados.io/question/sum-of-bit-differences-of-all-pairs?zen=true
//check for every bit position and count no of ones and zeros then the total pairs are zeros * ones * 2

#include<bits/stdc++.h>
using namespace std;

int main () {
    int n;
    cin >> n;

    vector<long> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    long sum = 0;
    for(int i = 0; i < 32; ++i) {
        long on = 0;
        for(auto x: a) {
            if((x & (1 << i)) != 0) on++;
        }
        sum += (on * (n - on) * 2);
    }

    cout << sum;
}
