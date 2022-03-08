//Link: https://nados.io/question/count-set-bits-in-first-n-natural-numbers?zen=true

#include<bits/stdc++.h>
using namespace std;

int largest(long num) {
    int mx = 1;
    while((1 << mx) <= num) mx++;
    return mx - 1;
}

long solve(long num) {
  if(num == 0) return 0;

  int mx = largest(num);
  return (1 << (mx - 1)) * mx + (num - (1 << mx) + 1) + solve(num - (1 << mx));
}

int main() {
    int n;
    cin >> n;

    cout << solve(n);
}