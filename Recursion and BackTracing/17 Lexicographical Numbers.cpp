//Link: https://nados.io/question/lexicographical-numbers?zen=true
#include<iostream>
using namespace std;

int n;

void dfs(int x) {
    if(x > n) return;
    else cout << x << "\n";

    for(int i = 0; i < 10; ++i) dfs(10 * x + i);
}

int main() {
    cin >> n;

    for(int i = 1; i < 10; ++i) dfs(i);
}