//Link: https://codeforces.com/edu/course/2/lesson/4/2/practice/contest/273278/problem/A

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

struct item {
    int seg, pref, suf, sum;
};
vector<item> values;
vector<int> ar;

item operator+ (item a, item b) {
    item ans;
    ans.seg = max({a.seg, b.seg, a.suf + b.pref});
    ans.pref = max(a.pref, a.sum + b.pref);
    ans.suf = max(b.suf, b.sum + a.suf);
    ans.sum = a.sum + b.sum;

    return ans;
}

void build(int l, int r, int x) {
    if(l == r) {
        if(l < ar.size()) {
            if(ar[l] < 0) values[x] = {0, 0, 0, ar[l]};
            else values[x] = {ar[l], ar[l], ar[l], ar[l]};
        }
        return;
    }

    int mid = (l + r) / 2;
    build(l, mid, 2 * x + 1);
    build(mid + 1, r, 2 * x + 2);

    values[x] = values[2 * x + 1] + values[2 * x + 2];
}
void upd(int i, int v, int x, int lx, int rx) {
    if(lx == rx) {
        if(v < 0) values[x] = {0, 0, 0, v};
        else values[x] = {v, v, v, v};
        return;
    }

    int mid = (lx + rx) / 2;

    if(i <= mid)
        upd(i, v, 2 * x + 1, lx, mid);
    else
        upd(i, v, 2 * x + 2, mid + 1, rx);

    values[x] = values[2 * x + 1] + values[2 * x + 2];
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

        values.resize(2 * x);
        ar.resize(n);
        read(ar);

        build(0, x - 1, 0);

        cout << values[0].seg << endl;
        while(m--) {
            int i, v;
            cin >> i >> v;
            upd(i, v, 0, 0, x - 1);

            cout << values[0].seg << endl;
        }
    }
}
