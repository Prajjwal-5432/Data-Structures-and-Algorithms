//Link: https://nados.io/question/get-maze-paths?zen=true
vector<string> paths;
void go(int i, int j, int r, int c, string asf) {
    if(i >= r or j >= c) return;
    if(i == r - 1 and j == c - 1) {
        paths.push_back(asf);
        return;
    }

    go(i, j + 1, r, c, asf + string("h"));
    go(i + 1, j, r, c, asf + string("v"));
}
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    go(0, 0, dr, dc, "");
    return paths;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}
