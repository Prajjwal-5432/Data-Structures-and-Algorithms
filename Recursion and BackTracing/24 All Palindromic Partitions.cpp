//Link: https://nados.io/question/all-palindromic-partitions?zen=true
#include <iostream>
using namespace std;

bool ispal(string s) {
  int i = 0, j = s.length() - 1;
  while(i <= j) {
    if(s[i] != s[j]) return 0;
    i++, j--;
  }
  return 1;
}

void solution(string str, string asf)
{
		if(str == ".") {
      cout << asf << "\n";
      return;
    }

    for(int i = 0; i < str.length(); ++i) {
      if(ispal(str.substr(0, i + 1))) {
        solution(str.substr(i + 1), asf + "(" + str.substr(0, i + 1) + ") ");
      }
    }
}

int main() 
{
  string str;    
  cin>>str;
  str += '.';
  solution(str,"");
  return 0;
}