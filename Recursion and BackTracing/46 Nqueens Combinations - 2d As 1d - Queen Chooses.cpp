//Link: https://nados.io/question/nqueens-combinations-2d-as-1d-queen-chooses?zen=true
#include<bits/stdc++.h>
using namespace std;

vector<vector<bool>> queen;
int n;
vector<int> col, ld, rd;

void nqueen(int row, int lcno) {
    if(row == n) {
        for(auto x: queen) {
            for(auto y: x) cout << (y ? "q\t" : "-\t");
            cout << endl;
        }
        cout << endl;
        return;
    }

    for(int i = lcno + 1; i < n; ++i) {
        int r = row;
        int c = i;

        if(!col[c] and !ld[r + c] and !rd[r - c + n - 1]) {
            col[c] = ld[r + c] = rd[r - c + n - 1] = 1;
            queen[r][c] = 1;
            nqueen(r + 1, -1);
            queen[r][c] = 0;
            col[c] = ld[r + c] = rd[r - c + n - 1] = 0;
        }
    }
}
int main() {
    cin >> n;

    queen.resize(n, vector<bool> (n, 0));

    col.resize(n, 0);
    ld.resize(2 * n - 1, 0);
    rd.resize(2 * n - 1, 0);

    nqueen(0, -1);
}