//Link: https://nados.io/question/solve-sudoku?zen=true
//Time: O(n^2)
#include<iostream>
using namespace std;

int a[9][9];

bool canPlace(int r, int c, int val) {
    for(int i = 0; i < 9; ++i) {
        if(a[i][c] == val) return 0;
    }

    for(int j = 0; j < 9; ++j) {
        if(a[r][j] == val) return 0;
    }

    int sr = 3 * (r / 3), sc = 3 * (c / 3);

    for(int i = sr; i < sr + 3; ++i) for(int j = sc; j < sc + 3; ++j) {
        if(a[i][j] == val) return 0;
    }

    return 1;
}

void dfs(int r, int c) {
    if(r == 9) {
        for(int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) cout << a[i][j] << ' ';
            cout << endl;
        }
        exit(0);
    }

    int ni, nj;
    if(c == 8) {
        ni = r + 1;
        nj = 0;
    } else {
        ni = r;
        nj = c + 1;
    }

    if(a[r][c]) dfs(ni, nj);
    else {
        for(int i = 1; i < 10; ++i) {
            if(canPlace(r, c, i)) {
                a[r][c] = i;
                dfs(ni, nj);
                a[r][c] = 0;
            }
        }
    }
}

int main() {
    for(int i = 0; i < 9; ++i) for(int j = 0; j < 9; ++j) cin >> a[i][j];
    dfs(0, 0);
}