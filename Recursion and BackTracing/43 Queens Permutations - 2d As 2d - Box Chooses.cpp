//Link: https://nados.io/question/queens-permutations-2d-as-2d-box-chooses?zen=true
#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> queen;
vector<bool> used;

void permute(int r, int c, int placed) {
    if(r == n) {
        if(placed == n) {
            for(auto x: queen) {
                for(auto y: x) {
                    if(y == 0) cout << "-\t";
                    else cout << "q" << y << "\t";
                }
                cout << endl;
            }
            cout << endl << endl;
        }
        return;
    }

    int nr, nc;
    if(c == n - 1) {
        nr = r + 1;
        nc = 0;
    } else {
        nr = r;
        nc = c + 1;
    }

    for(int i = 0; i < n; ++i) {
        if(!used[i]) {
            queen[r][c] = i + 1;
            used[i] = 1;
            permute(nr, nc, placed + 1);
            used[i] = 0;
            queen[r][c] = 0;
        }
    }

    permute(nr, nc, placed);
}

int main() {
    cin >> n;

    used.resize(n, 0);
    queen.resize(n, vector<int> (n, 0));
    permute(0, 0, 0);
}