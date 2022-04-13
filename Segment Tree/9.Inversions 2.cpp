//Link: https://codeforces.com/edu/course/2/lesson/4/3/practice/contest/274545/problem/B

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
int n;

void build(int l, int r, int x) {
    if(l == r) {
        if(l < n) seg[x] = 1;
        return;
    }

    int mid = (l + r) / 2;
    build(l, mid, 2 * x + 1);
    build(mid + 1, r, 2 * x + 2);

    seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
}
void upd(int i, int x, int lx, int rx) {
    if(lx == rx) {
        seg[x] = 0;
        return;
    }

    int mid = (lx + rx) / 2;

    if(i <= mid)
        upd(i, 2 * x + 1, lx, mid);
    else
        upd(i, 2 * x + 2, mid + 1, rx);

    seg[x] = seg[2 * x + 1] + seg[2 * x + 2];
}
int query(int k, int x, int lx, int rx) {
    if(lx == rx) return lx;

    int mid = (lx + rx) / 2;

    if(k >= seg[2 * x + 2])
        return query(k - seg[2 * x + 2], 2 * x + 1, lx, mid);
    else
        return query(k, 2 * x + 2, mid + 1, rx);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("input.txt", "w", stdout);

    int t = 1;
//    cin >> t;
    while(t--) {
        cin >> n;

        int x = 1;
        while(x <= n) x <<= 1;

        seg.resize(2 * x, 0);
        build(0, x - 1, 0);

        vector<int> v(n), ans;
        read(v);

        for(int i = n - 1; ~i; --i) {
            int ind = query(v[i], 0, 0, x - 1);
            upd(ind, 0, 0, x - 1);
            ans.push_back(ind + 1);
        }

        reverse(all(ans));
        speak(ans);
    }
}
