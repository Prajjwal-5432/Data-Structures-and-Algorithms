//Link: https://nados.io/question/next-greater-element-to-the-right?zen=true
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n), ans(n, -1);
  
    vector<int> t;
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
        while(!t.empty() and v[i] > v[t.back()]) {
          ans[t.back()] = i;
          t.pop_back();
        }
        t.push_back(i);
    }

    for(int i = 0; i < n; ++i) cout << (ans[i] == -1 ? -1 : v[ans[i]]) << endl;
    cout << endl;
}