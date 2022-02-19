//Link: https://nados.io/question/words-k-selection-4?zen=true
#include<bits/stdc++.h>
using namespace std;


void generateSelection(int cs, int ts, string ustr, vector<int> cnt, int ls, string asf) {
      if(cs == ts) {
        cout << asf << endl;
        return;
      }

      for(int i = ls; i < ustr.length(); ++i) {
        if(cnt[ustr[i] - 'a']) {
          cnt[ustr[i] - 'a']--;
          generateSelection(cs + 1, ts, ustr, cnt, i, asf + ustr[i]);
          cnt[ustr[i] - 'a']++;
        }
      }
}

int main(){
    string str;
    int k;
    cin >> str >> k;

    string ustr;
    vector<int> cnt(26, 0);

    for(auto x: str) {
      if(cnt[x - 'a'] == 0) ustr += x;
      cnt[x - 'a']++;
    }

    generateSelection(0 , k , ustr , cnt , 0, "") ;
    
}