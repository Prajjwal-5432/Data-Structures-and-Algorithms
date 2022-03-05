//Link: https://nados.io/question/josephus-special?zen=true
//Refer: https://www.youtube.com/watch?v=NjcMT9wZHV0&list=PL-Jc9J83PIiFJRioti3ZV7QabwoJK6eKe&index=4

#include<bits/stdc++.h>
using namespace std;
  
int solution(int n){
  int i = 1;
  while((i << 1) <= n) {
    i <<= 1;
  }
  return 2 * (n - i) + 1;
}


int main() {
  int n;
  cin >> n;
  cout << solution(n);
}