//Link: https://nados.io/question/queens-combinations-2d-as-2d-box-chooses?zen=true
#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> queen;
int n;

void combo(int r, int c, int placed) {
    if(r == n) {
        if(placed == n) {
            for(auto x: queen) {
                for(auto y: x) cout << y;
                cout << endl;
            }
            cout << endl;
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

    queen[r][c] = 'q';
    combo(nr, nc, placed + 1);
    queen[r][c] = '-';
    combo(nr, nc, placed);
}

int main() {
    cin >> n;

    queen.resize(n, vector<char> (n, '-'));

    combo(0, 0, 0);
}