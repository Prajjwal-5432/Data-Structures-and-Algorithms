//Link: https://nados.io/question/knights-tour?zen=true
//Time: O(8*(n^2))
vector<vector<int>> chess;
int n, placed;
int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};
void display(){
    for(int i=0;i<chess.size();i++){
        for(int j=0;j<chess.size();j++){
            cout << chess[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printKnightsTour(int r, int c){
    if(placed == n * n) {
        display();
        return;
    }

    for(int i = 0; i < 8; ++i) {
        int x = r + dx[i];
        int y = c + dy[i];

        if(min(x, y) >= 0 and max(x, y) < n and chess[x][y] == 0) {
            chess[x][y] = ++placed;
            printKnightsTour(x, y);
            placed--;
            chess[x][y] = 0;
        }
    }
}
  