//Link: https://nados.io/question/is-a-power-of-4?zen=true
//no of trailing zeros after the setbit should be even

#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    int flag = 1;
    flag &= !(n & (n - 1));
    flag &= (__builtin_ctzll(n) % 2 == 0);
    flag &= (n > 0);

    cout << (flag ? "true" : "false");
}