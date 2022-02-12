//Link: https://nados.io/question/gold-mine-2?zen=true
//Time: O(n^2)
#include<bits/stdc++.h>
using namespace std;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
vector<vector<int>> mat;
int n, m;

int dfs(int r, int c) {
    
    int val = mat[r][c];
    mat[r][c] = 0;

    int score = 0;
    for(int i = 0; i < 4; ++i) {
        int x = r + dx[i];
        int y = c + dy[i];

        if(x >= 0 and x < n and y >= 0 and y < m and mat[x][y]) {
            score = max(score, dfs(x, y));
        }
    }

    mat[r][c] = val;

    return score + val;
}

int main() {
    cin >> n >> m;

    mat.resize(n, vector<int> (m, 0));
    
    for(auto &x: mat) for(auto &y: x) cin >> y;

    int best = 0;
    for(int i = 0; i < n; ++i) for(int j = 0; j < m; ++j) {
        if(mat[i][j]) best = max(best, dfs(i, j));
    }    

    cout << best;
}