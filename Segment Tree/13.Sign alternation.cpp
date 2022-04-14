//Link: https://codeforces.com/edu/course/2/lesson/4/4/practice/contest/274684/problem/A

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

struct segtree{
    int x = 1;
    vector<int> v;

    void init(int n) {
        while(x <= n) x <<= 1;
        v.resize(2 * x, 0);
    }

    void upd(int i, int val, int x, int lx, int rx) {
        if(lx == rx) {
            v[x] = val;
            return;
        }

        int mid = (lx + rx) / 2;

        if(i <= mid)
            upd(i, val, 2 * x + 1, lx, mid);
        else
            upd(i, val, 2 * x + 2, mid + 1, rx);

        v[x] = v[2 * x + 1] + v[2 * x + 2];
    }

    int query(int l, int r, int x, int lx, int rx) {
        if(lx > r or rx < l) return 0;
        if(lx >= l and rx <= r) return v[x];

        int mid = (lx + rx) / 2;
        return query(l, r, 2 * x + 1, lx, mid) + query(l, r, 2 * x + 2, mid + 1, rx);
    }

    void upd(int i, int v) {
        upd(i, v, 0, 0, x - 1);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, x - 1);
    }
};

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

        segtree pos, neg;
        pos.init(n), neg.init(n);

        for(int i = 0, x; i < n; ++i) {
            cin >> x;
            if(i & 1) pos.upd(i, -x), neg.upd(i, x);
            else pos.upd(i, x), neg.upd(i, -x);
        }

        int m;
        cin >> m;
        while(m--) {
            int op;
            cin >> op;

            if(op == 0) {
                int i, val;
                cin >> i >> val;
                i--;

                if(i & 1) pos.upd(i, -val), neg.upd(i, val);
                else pos.upd(i, val), neg.upd(i, -val);
            } else {
                int l, r;
                cin >> l >> r;
                l--, r--;

                if(l & 1) cout << neg.query(l, r) << endl;
                else cout << pos.query(l, r) << endl;
            }
        }
    }
}
