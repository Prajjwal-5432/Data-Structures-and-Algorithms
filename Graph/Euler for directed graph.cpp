struct hierholzer {
	
	//for directed graph only

    vector<vector<int>> graf;
    vector<int> in, out, path;
    int n, edges;

    hierholzer(vector<vector<int>> &adj) {
        graf = adj;    
        n = graf.size();
        edges = 0;
    }
    
    vector<int> eulerPath() {
        prec();
        if(hasPath() == 0) return vector<int> ();
        
        dfs(startNode());
        reverse(path.begin(), path.end());
        
        if(path.size() != edges + 1) return vector<int> ();
        return path; // 0 indexed
    }
    
    void dfs(int v) {
        while(out[v] != 0) dfs(graf[v][--out[v]]);
        path.push_back(v);
    }
    
    void prec() {
        in = vector<int> (n, 0);
        out = vector<int> (n, 0);
        
        for(int i = 0; i < n; ++i) {
            for(auto &x: graf[i]) {
                out[i]++;
                in[x]++;
                edges++;
            }
        }
    }
    
    bool hasPath() {
        if(edges == 0) return 0;
        int startNodes = 0, endNodes = 0;
        for(int i = 0; i < n; ++i) {
            if(abs(out[i] - in[i]) > 1) return 0;
            else if(out[i] - in[i] == 1) startNodes++;
            else if(in[i] - out[i] == 1) endNodes++;
        }
        return (endNodes + startNodes == 0) or (endNodes == 1 and startNodes == 1);
    }
    
    int startNode() {
        int start = -1;
        for(int i = 0; i < n; ++i) {
            if(out[i] - in[i] == 1) return i;
            if(out[i] > 0) start = i;
        }
        return start;
    }
};