//Link:https://nados.io/question/basics-of-bit-manipulation?zen=true

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, i, j, k, m;
    cin >> n >> i >> j >> k >> m;

    cout << (n | (1 << i)) << endl;
    cout << (n & (~(1 << j))) << endl;
    cout << (n ^ (1 << k)) << endl;
    cout << ((n & (1 << m)) ? "true": "false");
}