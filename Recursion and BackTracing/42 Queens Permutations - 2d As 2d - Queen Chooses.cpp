//Link: https://nados.io/question/queens-permutations-2d-as-2d-queen-chooses?zen=true
#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> queen;
int n;

void permute(int placed) {
    if(placed == n) {
        for(auto x: queen) {
            for(auto y: x) {
                if(y == '-') cout << y;
                else cout << "q" << y;
                cout << "\t";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }

    for(int i = 0; i < n; ++i) for(int j = 0; j < n; ++j) {
        if(queen[i][j] == '-') {
            queen[i][j] = char(placed + 1 + '0');
            permute(placed + 1);
            queen[i][j] = '-';
        }
    }
}
int main() {
    cin >> n;
    queen.resize(n, vector<char> (n, '-'));

    permute(0);
}