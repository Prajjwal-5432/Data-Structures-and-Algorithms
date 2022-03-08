//Link: https://nados.io/question/check-divisibility-by-3?zen=true

#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;

    int ev = 0, od = 0;
    for(int i = 0; i < s.length(); ++i) {
        if(s[i] == '1') {
            if(i & 1) od++;
            else ev++;
        }
    }   

    if(abs(ev - od) % 3 == 0) cout << "true";
    else cout << "false";
}