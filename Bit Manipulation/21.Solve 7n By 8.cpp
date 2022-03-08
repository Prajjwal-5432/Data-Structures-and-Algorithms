//Link: https://nados.io/question/solve-7n-by-8?zen=true
//7n/8 can be written as (8n - n) / 8

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;

    cout << (((n << 3) - n) >> 3);
}