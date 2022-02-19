//Link: https://nados.io/question/coin-change-combinations-2?zen=true
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> coins;
vector<int> ans;

void combo(int amt, int idx) {
    if(amt == 0) {
        for(auto x: ans) cout << x << '-';
        cout << ".\n";
        return;
    }
    if(amt < 0 or idx == coins.size()) {
        return;
    }

    for(int i = amt / coins[idx]; i > 0; --i) {
        for(int j = 0; j < i; ++j) ans.push_back(coins[idx]);
        combo(amt - coins[idx] * i, idx + 1);
        for(int j = 0; j < i; ++j) ans.pop_back();
    }
    combo(amt, idx + 1);
}

int main() {
    cin >> n;
    coins.resize(n);

    for(auto &x: coins) cin >> x;

    int amt;
    cin >> amt;

    combo(amt, 0);
}