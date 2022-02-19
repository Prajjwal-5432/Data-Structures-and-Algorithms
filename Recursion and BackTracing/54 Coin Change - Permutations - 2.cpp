//Link: https://nados.io/question/coin-change-permutations-2?zen=true
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> v;
void permute(int amt, string asf) {
    if(amt < 0) return;
    if(amt == 0) {
        cout << asf << "." << endl;
        return;
    }
    for(int i = 0; i < n; ++i) {
        permute(amt - v[i], asf + to_string(v[i]) + "-");
    }
}
int main() {
    cin >> n;
    v.resize(n);
    for(auto &x: v) cin >> x;

    int amt;
    cin >> amt;
 
    permute(amt, "");
}