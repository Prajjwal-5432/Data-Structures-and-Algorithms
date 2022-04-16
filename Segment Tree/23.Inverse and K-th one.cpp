//Link: https://codeforces.com/edu/course/2/lesson/5/3/practice/contest/280799/problem/B

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
    int zeros, ones;
};

vector<item> seg;
vector<int> op;

item operator+ (item a, item b) {
    item c;
    c.zeros = a.zeros + b.zeros;
    c.ones = a.ones + b.ones;

    return c;
}
void build(int l, int r, int x, int n) {
    if(l == r) {
        if(l < n) seg[x] = {1, 0};
        return;
    }

    int mid = (l + r) / 2;
    build(l, mid, 2 * x + 1, n);
    build(mid + 1, r, 2 * x + 2, n);

    seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
}

void push(int x, int lx, int rx) {
    if(lx == rx or !op[x]) return;

    op[2 * x + 1] = op[x] - op[2 * x + 1];
    op[2 * x + 2] = op[x] - op[2 * x + 2];
    swap(seg[2 * x + 1].ones, seg[2 * x + 1].zeros);
    swap(seg[2 * x + 2].ones, seg[2 * x + 2].zeros);

    op[x] = 0;
}
void upd(int l, int r, int x, int lx, int rx) {
    push(x, lx, rx);
    if(lx > r or rx < l) return;
    if(lx >= l and rx <= r) {
        op[x] = 1;
        swap(seg[x].ones, seg[x].zeros);
        return;
    }

    int mid = (lx + rx) / 2;
    upd(l, r, 2 * x + 1, lx, mid);
    upd(l, r, 2 * x + 2, mid + 1, rx);

    seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
}
int query(int k, int x, int lx, int rx) {
    push(x, lx, rx);
    if(lx == rx) return lx;

    int mid = (lx + rx) / 2;
    if(seg[2 * x + 1].ones > k)
        return query(k, 2 * x + 1, lx, mid);

    return query(k - seg[2 * x + 1].ones, 2 * x + 2, mid + 1, rx);
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

        seg.resize(2 * x, {0, 0});
        op.resize(2 * x, 0);

        build(0, x - 1, 0, n);

        while(m--) {
            int oper;
            cin >> oper;

            if(oper == 1) {
                int l, r;
                cin >> l >> r;
                upd(l, r - 1, 0, 0, x - 1);
            } else {
                int k;
                cin >> k;
                cout << query(k, 0, 0, x - 1) << endl;
            }
        }
    }
}
