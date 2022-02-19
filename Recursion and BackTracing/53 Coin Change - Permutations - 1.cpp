//Link: https://nados.io/question/coin-change-permutations-1?zen=true
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
vector<bool> used;
void permute(int amt, string asf) {
    if(amt < 0) return;
    if(amt == 0) {
        cout << asf << "." << endl;
        return;
    }
    for(int i = 0; i < n; ++i) {
        if(!used[i]) {
            used[i] = 1;
            permute(amt - v[i], asf + to_string(v[i]) + "-");
            used[i] = 0;
        }
    }
}
int main() {
    cin >> n;
    v.resize(n);
    used.resize(n, 0);
    for(auto &x: v) cin >> x;

    int amt;
    cin >> amt;
 
    permute(amt, "");
}