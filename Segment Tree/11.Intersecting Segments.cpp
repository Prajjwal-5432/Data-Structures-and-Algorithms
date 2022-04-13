//Link: https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/D

#include<iostream>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<unordered_set>
#include<algorithm>

using namespace std;

#define endl                   '\n'
#define Max                    LLONG_MAX
#define Min                    LLONG_MIN
#define Mod                    1000000007
#define remin(a, b)            a = a < b ? a : b
#define remax(a, b)            a = a > b ? a : b
#define nps                    string::npos
#define int                    int64_t
#define cont(it, s)            for(auto it = s.begin(); it != s.end(); ++it)
#define rep(i, s, n)           for(int i = s; i < n; ++i)
#define repr(i, n, s)          for(int i = n; i >= s; --i)
#define read(a)                for(auto& xy: a) cin >> xy
#define speak(a)               for(auto xy: a) cout << xy << ' '; cout << endl
#define work(xy, a)            for(auto& xy: a)
#define dbg(x)                 cerr << (#x) << " is " << (x) << endl
#define all(xy)                (xy).begin(), (xy).end()
#define rall(xy)               (xy).rbegin(), (xy).rend()
vector<int> seg;

void upd(int i, int x, int lx, int rx) {
    if(lx == rx) {
        seg[x] = 1 - seg[x];
        return;
    }

    int mid = (lx + rx) / 2;

    if(i <= mid)
        upd(i, 2 * x + 1, lx, mid);
    else
        upd(i, 2 * x + 2, mid + 1, rx);

    seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
}

int query(int l, int r, int x, int lx, int rx) {
    if(lx > r or rx < l) return 0;
    if(lx >= l and rx <= r) return seg[x];

    int mid = (lx + rx) / 2;
    return query(l, r, 2 * x + 1, lx, mid) + query(l, r, 2 * x + 2, mid + 1, rx);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("input.txt", "w", stdout);

    int t = 1;
//    cin >> t;
    while(t--) {
        int n;
        cin >> n;

        n <<= 1;

        int x = 1;
        while(x <= n) x <<= 1;

        seg.resize(2 * x, 0);

        vector<int> vis(n / 2 + 1, -1), v(n), ans(n / 2, 0);
        read(v);

        for(int i = 0; i < n; ++i) {
            if(vis[v[i]] == -1) {
                vis[v[i]] = i;
                upd(i, 0, 0, x - 1);
            } else {
                ans[v[i] - 1] += query(vis[v[i]] + 1, i, 0, 0, x - 1);
                upd(vis[v[i]], 0, 0, x - 1);
            }
        }

        fill(all(vis), -1);
        seg.assign(2 * x, 0);

        for(int i = n - 1; ~i; --i) {
            if(vis[v[i]] == -1) {
                vis[v[i]] = i;
                upd(i, 0, 0, x - 1);
            } else {
                ans[v[i] - 1] += query(i, vis[v[i]] - 1, 0, 0, x - 1);
                upd(vis[v[i]], 0, 0, x - 1);
            }
        }

        speak(ans);
    }
}
