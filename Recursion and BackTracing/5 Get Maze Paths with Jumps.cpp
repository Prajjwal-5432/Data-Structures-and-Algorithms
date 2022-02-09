//Link: https://nados.io/question/get-maze-path-with-jumps?zen=true
vector<string> ans;
void go(int i, int j, int r, int c, string asf) {
    if(i >= r or j >= c) return;
    if(i == r - 1 and j == c - 1) {
        ans.push_back(asf);
        return;
    }

    for(int cc = 1; cc < c; ++cc) go(i, j + cc, r, c, asf + string("h") + to_string(cc));
    for(int cr = 1; cr < r; ++cr) go(i + cr, j, r, c, asf + string("v") + to_string(cr));
    for(int d = 1; d < r + c; ++d) go(i + d, j + d, r, c, asf + string("d") + to_string(d));
}
vector<string> get_maze_paths(int sr, int sc, int dr, int dc) {
    go(0, 0, dr, dc, "");
    return ans;
}