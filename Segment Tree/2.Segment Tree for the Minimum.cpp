//Link: https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/B

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

vector<int> seg, ar;
void build(int l, int r, int x) {
    if(l == r) {
        if(l < ar.size()) {
            seg[x] = ar[l];
        }
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * x + 1);
    build(mid + 1, r, 2 * x + 2);

    seg[x] = min(seg[2 * x + 1], seg[2 * x + 2]);
}
void upd(int i, int v, int x, int lx, int rx) {
    if(lx == rx) {
        seg[x] = v;
        return;
    }
    int mid = (lx + rx) / 2;

    if(i <= mid)
        upd(i, v, 2 * x + 1, lx, mid);
    else
        upd(i, v, 2 * x + 2, mid + 1, rx);

    seg[x] = min(seg[2 * x + 1], seg[2 * x + 2]);
}
int query(int l, int r, int x, int lx, int rx) {
    if(lx > r or rx < l) return Max;
    else if(lx >= l and rx <= r) return seg[x];
    int mid = (lx + rx) / 2;
    return min(query(l, r, 2 * x + 1, lx, mid), query(l, r, 2 * x + 2, mid + 1, rx));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("input.txt", "w", stdout);


    int t = 1;
    while(t--) {
        int n, m;
        cin >> n >> m;

        int x = 1;
        while(x < n) x <<= 1;

        seg.resize(2 * x, Max);
        ar.resize(n);

        read(ar);
        build(0, x, 0);

        while(m--) {
            int op;
            cin >> op;
            if(op == 1) {
                int i, v;
                cin >> i >> v;

                upd(i, v, 0, 0, x);
            } else {
                int l, r;
                cin >> l >> r;
                cout << query(l, r - 1, 0, 0, x) << endl;
            }
        }
    }
}
