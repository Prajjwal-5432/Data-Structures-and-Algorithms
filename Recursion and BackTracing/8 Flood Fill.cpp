//Link: https://nados.io/question/flood-fill?zen=true
//Time: O(n^2)
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};
char dir[] = {'t', 'l', 'd', 'r'};
vector < vector < int >> arr;
vector<vector<bool>> vis;

void go(int i, int j, string asf) {
    if(i == arr.size() - 1 and j == arr[0].size() - 1) {
        cout << asf << "\n";
        return;
    }

    for(int t = 0; t < 4; ++t) {
        int x = i + dx[t];
        int y = j + dy[t];
        if(x >= 0 and x < arr.size() and y >= 0 and y < arr[0].size() and !arr[x][y] and !vis[x][y]) {
            vis[x][y] = 1;
            go(x, y, asf + dir[t]);
            vis[x][y] = 0;
        }
    }
}
