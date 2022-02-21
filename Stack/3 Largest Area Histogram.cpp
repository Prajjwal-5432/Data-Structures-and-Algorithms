//Link: https://nados.io/question/largest-area-histogram?zen=true
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(auto &x: a) cin >> x;

    vector<int> r(n, n), l(n, -1);

    vector<int> v;

    for(int i = 0; i < n; ++i) {
        while(!v.empty() and a[i] < a[v.back()]) {
            r[v.back()] = i;
            v.pop_back();
        }
        v.push_back(i);
    }

    v.clear();

    for(int i = n - 1; i >= 0; --i) {
        while(!v.empty() and a[i] < a[v.back()]) {
            l[v.back()] = i;
            v.pop_back();
        }
        v.push_back(i);
    }

    int mx = 0;

    for(int i = 0; i < n; ++i) mx = max(mx, a[i] * (r[i] - l[i] - 1));

    cout << mx << endl;
}