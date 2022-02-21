//Link: https://nados.io/question/stock-span?zen=true
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<pair<int, int>> v;

    for(auto &x: a) cin >> x;

    for(int i = 0; i < n; ++i) {
        int cnt = 1;
        while(!v.empty() and v.back().first < a[i]) {
            cnt += v.back().second;
            v.pop_back();
        }
        v.push_back({a[i], cnt});
        cout << cnt << endl;
    }
    cout << endl;
}