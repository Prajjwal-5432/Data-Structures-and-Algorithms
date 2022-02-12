//Link: https://nados.io/question/max-score?zen=true
//Time: O(2 ^ n)
#include<bits/stdc++.h>
using namespace std;

int val[26], n;
vector<string> v;

int getScore(int idx, int score, unordered_map<char, int> cnt) {
    if(idx == n) return score;

    vector<int> c(26, 0);

    for(auto x: v[idx]) c[x - 'a']++;

    bool flag = 1;
    for(int i = 0; i < 26; ++i) flag &= cnt[i + 'a'] >= c[i];

    int yes = 0;
    if(flag) {
        for(int i = 0; i < 26; ++i) cnt[i + 'a'] -= c[i];

        int cs = 0;
        for(auto x: v[idx]) cs += val[x - 'a'];
        
        yes = getScore(idx + 1, score + cs, cnt);
        for(int i = 0; i < 26; ++i) cnt[i + 'a'] += c[i];
    }

    return max(yes, getScore(idx + 1, score, cnt));
}

int main() {
    cin >> n;
    
    v.resize(n);

    unordered_map<char, int> cnt;

    for(int i = 0; i < n; ++i) cin >> v[i];

    int x;
    cin >> x;

    for(int i = 0; i < x; ++i) {
        char c;
        cin >> c;
        cnt[c]++;
    }

    for(int i = 0; i < 26; ++i) cin >> val[i];

    cout << getScore(0, 0, cnt);
}