//Link: https://nados.io/question/abbreviation-1-using-bits?zen=true

#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    for(int i = 0; i < (1 << s.length()); ++i) {
        string ans;
        int cnt = 0;
        for(int j = 0; j < s.length(); ++j) {
            int bth = s.length() - j - 1;

            if((i & (1 << bth)) == 0) ans += (cnt ? to_string(cnt) : "") +  s[j], cnt = 0;
            else cnt++;
        }
        if(cnt) ans += to_string(cnt);
        cout << ans << endl;
    }
}