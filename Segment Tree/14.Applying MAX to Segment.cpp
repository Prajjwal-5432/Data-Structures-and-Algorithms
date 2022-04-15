//Link: https://codeforces.com/edu/course/2/lesson/5/1/practice/contest/279634/problem/B

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
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
void upd(int l, int r, int val, int x, int lx, int rx) {
    if(lx > r or rx < l) return;
    if(lx >= l and rx <= r) {
        seg[x] = max(seg[x], val);
        return;
    }

    int mid = (lx + rx) / 2;
    upd(l, r, val, 2 * x + 1, lx, mid);
    upd(l, r, val, 2 * x + 2, mid + 1, rx);
}
int query(int i, int x, int lx, int rx) {
    if(lx == rx) return seg[x];
    int mid = (lx + rx) / 2;

    if(i <= mid)
        return max(seg[x], query(i, 2 * x + 1, lx, mid));
    return max(seg[x], query(i, 2 * x + 2, mid + 1, rx));
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t = 1;
//    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;

        int x = 1;
        while(x <= n) x <<= 1;

        seg.resize(2 * x, 0);

        while(m--) {
            int op;
            cin >> op;

            if(op == 1) {
                int l, r, v;
                cin >> l >> r >> v;

                upd(l, r - 1, v, 0, 0, x - 1);
            } else {
                int ind;
                cin >> ind;
                cout << query(ind, 0, 0, x - 1) << endl;
            }
        }
    }
}
