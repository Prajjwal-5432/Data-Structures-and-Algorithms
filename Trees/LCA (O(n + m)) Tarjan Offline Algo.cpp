#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(xy) (xy).begin(), (xy).end()
#define read(a) for (auto& xy : a) cin >> xy
#define sort_unique(c)         (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))

const int nx = 2e5 + 100;
vector<int> graf[nx];
vector<array<int, 2>> query[nx];
int par[nx], lev[nx], anc[nx], vis[nx], sol[nx];
int fset(int v) {
    return v == par[v] ? v : par[v] = fset(par[v]);
}
void uset(int u, int v) {
    u = fset(u), v = fset(v);
    if(u != v) {
        if(lev[u] < lev[v]) swap(u, v);
        par[v] = u;
        lev[u] += lev[v];
    }
}
void dfs(int v) {
    vis[v] = 1;
    anc[v] = v;
    for(auto x: graf[v]) {
        if(!vis[x]) {
            dfs(x);
            uset(x, v);
            anc[fset(v)] = v;
        }
    }
    
    for(auto x: query[v]) {
        if(vis[x[0]]) {
            sol[x[1]] = anc[fset(x[0])];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int tt = 1;
    // cin >> tt;
    while(tt--) {
        ll n, q;
        cin >> n >> q;
        rep(i, 0, n + 10) par[i] = i, lev[i] = 1;
        rep(i, 2, n + 1) {
            ll x;
            cin >> x;
            graf[x].push_back(i);
        }
        
        rep(i, 0, q) {
            int u, v;
            cin >> u >> v;
            query[u].push_back({v, i});
            query[v].push_back({u, i});
        }
        
        dfs(1);
        rep(i, 0, q) cout << sol[i] << endl;
    }
}