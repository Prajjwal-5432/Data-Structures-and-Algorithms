//Link: https://nados.io/question/permutations-2?zen=true
#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;
vector<bool> used;

void permute(int idx, int left) {
    if(idx == n) {
        if(left == 0) {
            for(auto x: v) cout << x;
            cout << endl;   
        }
        return;
    }
    for(int i = 1; i < k + 1; ++i) {
        if(!used[i - 1]) {
            used[i - 1] = 1;
            v[idx] = i;
            permute(idx + 1, left - 1);
            used[i - 1] = 0;
            v[idx] = 0;
        }
    }
    permute(idx + 1, left);
}

int main() {
    cin >> n >> k;
    v.resize(n, 0);
    used.resize(k, 0);
    permute(0, k);
}