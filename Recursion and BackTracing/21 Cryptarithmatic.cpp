//Link: https://nados.io/question/cryptarithmetic?zen=true
//Time: O(n!)
#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

string s1, s2, s3;
cc_hash_table<char, int> mp;
vector<bool> used(10, 0);

bool good() {
    int64_t num1, num2, num3;
    num1 = num3 = num2 = 0;

    for(int i = 0; i < s1.length(); ++i) num1 = num1 * 10 + mp[s1[i]];
    for(int i = 0; i < s2.length(); ++i) num2 = num2 * 10 + mp[s2[i]];
    for(int i = 0; i < s3.length(); ++i) num3 = num3 * 10 + mp[s3[i]];

    return num1 + num2 == num3;
}

void getCombo(string unique, int idx) {
    if(idx == unique.length()) {
        if(good()) {
            for(char x = 'a'; x <= 'z'; ++x) {
                if(mp.find(x) != mp.end()) cout << x << "-" << mp[x] << " ";
            }
            cout << "\n";
        }
        return;
    }

    for(int i = 0; i < 10; ++i) {
        if(!used[i]) {
            mp[unique[idx]] = i;
            used[i] = 1;
            getCombo(unique, idx + 1);
            mp[unique[idx]] = -1;
            used[i] = 0;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string unique;
    cin >> s1 >> s2 >> s3;

    for(int i = 0; i < s1.length(); ++i) {
        if(mp.find(s1[i]) == mp.end()) {
            mp[s1[i]] = -1;
            unique += s1[i];
        }
    }
    for(int i = 0; i < s2.length(); ++i) {
        if(mp.find(s2[i]) == mp.end()) {
            mp[s2[i]] = -1;
            unique += s2[i];
        }
    }
    for(int i = 0; i < s3.length(); ++i) {
        if(mp.find(s3[i]) == mp.end()) {
            mp[s3[i]] = -1;
            unique += s3[i];
        }
    }

    getCombo(unique, 0);
}