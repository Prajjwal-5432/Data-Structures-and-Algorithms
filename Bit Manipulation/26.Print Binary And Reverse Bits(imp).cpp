//Link: https://nados.io/question/print-binary-and-reverse-bits?zen=true

#include<bits/stdc++.h>
using namespace std;

string s;
void dec2bin(int n) {
  if(n / 2 != 0) dec2bin(n / 2);
  s += char(n % 2 + '0');
}

int main(){
  int n;
  cin >> n;

  dec2bin(n);

  cout << s << endl;
  reverse(s.begin(), s.end());
  cout << stoll(s, 0, 2);
}