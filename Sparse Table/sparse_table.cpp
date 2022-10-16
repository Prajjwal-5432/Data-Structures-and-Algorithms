struct sparse_table {
    int level, n;
    vector<vector<int>> mx, mn;
    vector<int> lg;
    
    sparse_table(vector<int> &a) {
        n = a.size();
        level = ceil(log2(n));
        mx.resize(n, vector<int> (level + 1));
        mn.resize(n, vector<int> (level + 1));
        lg.resize(n + 1);
        build(a);
    }
    
    void build(vector<int> &a) {
        lg[1] = 0;
        for(int i = 2; i < n + 1; ++i)
            lg[i] = lg[i / 2] + 1;
        
        for(int i = 0; i < n; ++i) 
            mn[i][0] = mx[i][0] = a[i];
        
        for(int j = 1; j <= level; ++j) {
            for(int i = 0; i + (1LL << j) <= n; ++i) {
                mx[i][j] = max(mx[i][j - 1], mx[i + (1LL << (j - 1))][j - 1]);
                mn[i][j] = min(mn[i][j - 1], mn[i + (1LL << (j - 1))][j - 1]);
            }
        }
    }
    
    int get_max(int l, int r) {
        l--, r--;
        int j = lg[r - l + 1];
        return max(mx[l][j], mx[r - (1LL << j) + 1][j]);
    }
    
    int get_min(int l, int r) {
        l--, r--;
        int j = lg[r - l + 1];
        return min(mn[l][j], mn[r - (1LL << j) + 1][j]);    
    }
};