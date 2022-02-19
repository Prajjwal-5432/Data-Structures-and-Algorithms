//Link: https://nados.io/question/queens-combinations-2d-as-2d-queen-chooses?zen=true
#include<bits/stdc++.h>
using namespace std;
vector<vector<bool>> queen;
int n;

void combo(int r, int c, int placed) {
    if(placed == n) {
        for(auto x: queen) {
            for(auto y: x) cout << (y ? "q\t" : "-\t");
            cout << endl;
        }
        cout << endl;
        return;
    }
    for(int j = c + 1; j < n; ++j) {
        queen[r][j] = 1;
        combo(r, j, placed + 1);
        queen[r][j] = 0;
    }

    for(int i = r + 1; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            queen[i][j] = 1;
            combo(i, j, placed + 1);
            queen[i][j] = 0;
        }
    }
}

int main() {
    cin >> n;

    queen.resize(n, vector<bool> (n, 0));
    combo(0, -1, 0);
}