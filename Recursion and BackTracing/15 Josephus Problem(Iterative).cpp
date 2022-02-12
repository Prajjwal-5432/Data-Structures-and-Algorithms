//Link: https://nados.io/question/josephus-problem?zen=true
//Time: O(n)
#include<iostream>
using namespace std;

int main() {
    int n, k, res = 0;

    cin >> n >> k;

    for(int i = 2; i < n + 1; ++i) res = (res + k) % i;

    cout << res;
}