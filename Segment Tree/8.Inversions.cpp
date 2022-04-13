//Link: https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/A

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
        seg[x] = 1;
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
    while(t--) {
        int n;
        cin >> n;

        int x = 1;
        while(x < n + 1) x <<= 1;

        seg.resize(2 * x, 0);

        for(int i = 0, val; i < n; ++i) {
            cin >> val;
            cout << query(val + 1, n, 0, 0, x - 1) << ' ';
            upd(val, 0, 0, x - 1);
        }
    }
}
