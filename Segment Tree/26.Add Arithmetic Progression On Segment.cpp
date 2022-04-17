//Link: https://codeforces.com/edu/course/2/lesson/5/4/practice/contest/280801/problem/B

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

struct item {
    int a, dl, d;
};
vector<item> seg;
void upd(int l, int r, int a, int d, int x, int lx, int rx) {
    if(lx > r or rx < l) return;
    if(lx >= l and rx <= r) {
        seg[x].a += a;
        seg[x].dl += d * l;
        seg[x].d += d;
        return;
    }

    int mid = (lx + rx) / 2;
    upd(l, r, a, d, 2 * x + 1, lx, mid);
    upd(l, r, a, d, 2 * x + 2, mid + 1, rx);
}
int query(int ind, int x, int lx, int rx) {
    if(lx == rx) return seg[x].a - seg[x].dl + seg[x].d * ind;

    int mid = (lx + rx) / 2;
    int res;
    if(ind <= mid)
        res = query(ind, 2 * x + 1, lx, mid);
    else
        res = query(ind, 2 * x + 2, mid + 1, rx);

    return res + seg[x].a - seg[x].dl + seg[x].d * ind;
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

        seg.resize(2 * x, {0, 0, 0});

        while(m--) {
            int op;
            cin >> op;

            if(op == 1) {
                int l, r, a, d;
                cin >> l >> r >> a >> d;
                upd(l - 1, r - 1, a, d, 0, 0, x - 1);
            } else {
                int ind;
                cin >> ind;
                cout << query(ind - 1, 0, 0, x - 1) << endl;
            }
        }
    }
}
