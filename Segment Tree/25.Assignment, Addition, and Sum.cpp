//Link: https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/A

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
#define mod                    1000000007
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

vector<int> seg, op, val;
void push(int x, int lx, int rx) {
    if(lx == rx or op[x] == 0) return;

    int mid = (lx + rx) / 2;
    if(op[x] == 1) {
        seg[2 * x + 1] = val[x] * (mid - lx + 1);
        seg[2 * x + 2] = val[x] * (rx - mid);
        op[2 * x + 1] = op[2 * x + 2] = op[x];
        val[2 * x + 1] = val[2 * x + 2] = val[x];
    } else {
        seg[2 * x + 1] += val[x] * (mid - lx + 1);
        seg[2 * x + 2] += val[x] * (rx - mid);
        op[2 * x + 1] = op[2 * x + 1] ? op[2 * x + 1] : 2;
        op[2 * x + 2] = op[2 * x + 2] ? op[2 * x + 2] : 2;
        val[2 * x + 1] += val[x];
        val[2 * x + 2] += val[x];
    }
    op[x] = val[x] = 0;
}
void upd(int l, int r, int v, int k, int x, int lx, int rx) {
    push(x, lx, rx);
    if(lx > r or rx < l) return;
    if(lx >= l and rx <= r) {
        if(k == 1) {
            seg[x] = v * (rx - lx + 1);
            op[x] = 1;
            val[x] += v;
        } else {
            seg[x] += v * (rx - lx + 1);
            op[x] = (op[x] ? op[x] : 2);
            val[x] += v;
        }
        return;
    }

    int mid = (lx + rx) / 2;
    upd(l, r, v, k, 2 * x + 1, lx, mid);
    upd(l, r, v, k, 2 * x + 2, mid + 1, rx);

    seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
}
int query(int l, int r, int x, int lx, int rx) {
    push(x, lx, rx);
    if(lx > r or rx < l) return 0;
    if(lx >= l and rx <= r) return seg[x];

    int mid = (lx + rx) / 2;
    return query(l, r, 2 * x + 1, lx, mid) + query(l, r, 2 * x + 2, mid + 1, rx);
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
        op.resize(2 * x, 0);
        val.resize(2 * x, 0);

        while(m--) {
            int oper;
            cin >> oper;
            if(oper == 1) {
                int l, r, v;
                cin >> l >> r >> v;
                upd(l, r - 1, v, oper, 0, 0, x - 1);
            } else if(oper == 2) {
                int l, r, v;
                cin >> l >> r >> v;
                upd(l, r - 1, v, oper, 0, 0, x - 1);
            } else {
                int l, r;
                cin >> l >> r;
                cout << query(l, r - 1, 0, 0, x - 1) << endl;
            }
        }
    }
}
