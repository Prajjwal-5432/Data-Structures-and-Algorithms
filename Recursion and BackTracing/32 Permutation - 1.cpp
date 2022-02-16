//Link: https://nados.io/question/permutation-1?zen=true
#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v;

void permute(int val) {
    if(val > k) {
        for(auto x: v) cout << x;
        cout << endl;   
        return;
    }

    for(int i = 0; i < v.size(); ++i) {
        if(v[i] == 0) {
            v[i] = val;
            permute(val + 1);
            v[i] = 0;
        }
    }
}

int main() {
    cin >> n >> k;
    v.resize(n, 0);
    permute(1);
}