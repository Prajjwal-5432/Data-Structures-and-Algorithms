//Link: https://nados.io/question/all-repeating-except-one?zen=true

#include<bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  int ans = 0;
  for(int i = 0, x; i < n; ++i) {
    cin >> x;
    ans ^= x;
  }

  cout << ans;
 
}