//Link:https://nados.io/question/is-a-power-of-2?zen=true

#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;

    // cout << (__builtin_popcount(n) == 1 ? "true" : "false");
    cout << ((n & (n - 1)) ? "false" : "true");
}