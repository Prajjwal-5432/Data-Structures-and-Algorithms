struct sparse_table {
    ll level, n;
    vector<vector<ll>> table;
    vector<ll> lg;
    
    sparse_table(vector<ll> &a) {
        n = a.size();
        level = ceil(log2(n));
        table.resize(n, vector<ll> (level + 1));
        lg.resize(n + 1);
        build(a);
    }
    
    void build(vector<ll> &a) {
        lg[1] = 0;
        for(int i = 2; i < n + 1; ++i)
            lg[i] = lg[i / 2] + 1;
            
        for(int i = 0; i < n; ++i) 
            table[i][0] = a[i];
        
        for(int j = 1; j <= level; ++j) {
            for(int i = 0; i + (1LL << j) <= n; ++i) {
                table[i][j] = max(table[i][j - 1], table[i + (1LL << (j - 1))][j - 1]);
            }
        }
    }
    
    ll query(ll l, ll r) {
        l--, r--;
        ll j = lg[r - l + 1];
    
        return max(table[l][j], table[r - (1LL << j) + 1][j]);
    }
};