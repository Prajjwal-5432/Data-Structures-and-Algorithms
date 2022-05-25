const int N = 3e5, M = N;
//=======================
const int MAX = 1e6;
int a[N];

struct wavelet_tree {
    int lo, hi;
    wavelet_tree *lef, *rig;
    vector<int> b;
    vector<long long> c; // c holds the prefix sum of elements

    //nos are in range [x,y]
    //array indices are [from, to)
    wavelet_tree(int *from, int *to, int x, int y) {
        lo = x, hi = y;
        if (from >= to)
            return;
        if (hi == lo) {
            b.reserve(to - from + 1);
            b.push_back(0);
            c.reserve(to - from + 1);
            c.push_back(0);
            for (auto it = from; it != to; it++) {
                b.push_back(b.back() + 1);
                c.push_back(c.back() + *it);
            }
            return;
        }
        int mid = (lo + hi) / 2;
        auto f = [mid](int x) {
            return x <= mid;
        };
        b.reserve(to - from + 1);
        b.push_back(0);
        c.reserve(to - from + 1);
        c.push_back(0);
        for (auto it = from; it != to; it++) {
            b.push_back(b.back() + f(*it));
            c.push_back(c.back() + *it);
        }
        //see how lambda function is used here
        auto pivot = stable_partition(from, to, f);
        lef = new wavelet_tree(from, pivot, lo, mid);
        rig = new wavelet_tree(pivot, to, mid + 1, hi);
    }

    // swap a[i] with a[i+1]  , if a[i]!=a[i+1] call swapadjacent(i)
    void swapadjacent(int i) {
        if (lo == hi)
            return;
        b[i] = b[i - 1] + b[i + 1] - b[i];
        c[i] = c[i - 1] + c[i + 1] - c[i];
        if (b[i + 1] - b[i] == b[i] - b[i - 1]) {
            if (b[i] - b[i - 1])
                return this->lef->swapadjacent(b[i]);
            else
                return this->rig->swapadjacent(i - b[i]);
        } else
            return;
    }

    //kth smallest element in [l, r]
    int kth(int l, int r, int k) {
        if (l > r)
            return 0;
        if (lo == hi)
            return lo;
        int inLeft = b[r] - b[l - 1];
        int lb = b[l - 1]; //amt of nos in first (l-1) nos that go in left
        int rb = b[r]; //amt of nos in first (r) nos that go in left
        if (k <= inLeft)
            return this->lef->kth(lb + 1, rb, k);
        return this->rig->kth(l - lb, r - rb, k - inLeft);
    }

    //count of nos in [l, r] Less than or equal to k
    int LTE(int l, int r, int k) {
        if (l > r or k < lo)
            return 0;
        if (hi <= k)
            return r - l + 1;
        int lb = b[l - 1], rb = b[r];
        return this->lef->LTE(lb + 1, rb, k) + this->rig->LTE(l - lb, r - rb, k);
    }

    //count of nos in [l, r] equal to k
    int count(int l, int r, int k) {
        if (l > r or k < lo or k > hi)
            return 0;
        if (lo == hi)
            return r - l + 1;
        int lb = b[l - 1], rb = b[r], mid = (lo + hi) / 2;
        if (k <= mid)
            return this->lef->count(lb + 1, rb, k);
        return this->rig->count(l - lb, r - rb, k);
    }

    //sum of nos in [l ,r] less than or equal to k
    long long sumk(int l, int r, int k) {
        if (l > r or k < lo)
            return 0;
        if (hi <= k)
            return c[r] - c[l - 1];
        int lb = b[l - 1], rb = b[r];
        return this->lef->sumk(lb + 1, rb, k) + this->rig->sumk(l - lb, r - rb, k);
    }

    ~wavelet_tree() {
        delete lef;
        delete rig;
    }
};