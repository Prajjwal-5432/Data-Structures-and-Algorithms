#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define repr(i, a, b) for(int i = a; i >= b; --i)
#define all(xy) (xy).begin(), (xy).end()
#define read(a) for (auto& xy : a) cin >> xy
#define sort_unique(c)         (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))

const int lg = 25;
const int nx = 2e5 + 100;
int far[lg + 1][nx];
int lev[nx];
int lca(int x, int y) {
    if(lev[x] < lev[y]) swap(x, y);
    repr(h, lg, 0) {
        if(lev[y] + (1LL << h) <= lev[x]) x = far[h][x];
    }
    if(x == y) return x;
    repr(h, lg, 0) {
        if(far[h][x] != far[h][y]) {
            x = far[h][x], y = far[h][y];
        }
    }
    return far[0][x];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, q;
    cin >> n >> q;
    rep(i, 2, n + 1) cin >> far[0][i];
    rep(h, 1, lg + 1) rep(i, 1, n + 1) far[h][i] = far[h - 1][far[h - 1][i]];
    rep(i, 2, n + 1) lev[i] = lev[far[0][i]] + 1;

    while(q--) {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << endl;
    }
}