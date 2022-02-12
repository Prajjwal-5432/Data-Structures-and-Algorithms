//Link: https://nados.io/question/josephus-problem?zen=true
//Time: O(n)
#include<iostream>
using namespace std;

int k;

int calc(int n) {
    return n == 1 ? 0 : (k + calc(n - 1)) % n;
}

int main() {
    int n;
    cin >> n >> k;
    cout << calc(n);
}