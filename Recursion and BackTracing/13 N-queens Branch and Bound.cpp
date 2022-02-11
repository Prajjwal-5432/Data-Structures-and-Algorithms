//Link: https://nados.io/question/n-queens-branch-and-bound?zen=true
int n;
vector<int> col, ld, rd;

void placeQueen(int row, string asf) {
    if(row == n) {
        cout << asf << ".\n";
        return;
    }

    for(int i = 0; i < n; ++i) {
        if(col[i] == 0 and ld[row + i] == 0 and rd[row - i + n - 1] == 0) {
            col[i] = ld[row + i] = rd[row - i + n - 1] = 1;
            placeQueen(row + 1, asf + to_string(row) + "-" + to_string(i) + ", ");
            col[i] = ld[row + i] = rd[row - i + n - 1] = 0;
        }
    }
}