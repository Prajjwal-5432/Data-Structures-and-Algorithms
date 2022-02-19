//Link: https://nados.io/question/coin-change-combinations-1?zen=true
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> coins;

void combo(int amt, int idx, string asf) {
    if(amt == 0) {
        cout << asf << "." << endl;
        return;
    }
    if(amt < 0 or idx == coins.size()) return;

    combo(amt - coins[idx], idx + 1, asf + to_string(coins[idx]) + "-");
    combo(amt, idx + 1, asf);
}

int main() {
    cin >> n;
    coins.resize(n);

    for(auto &x: coins) cin >> x;

    int amt;
    cin >> amt;

    combo(amt, 0, "");
}