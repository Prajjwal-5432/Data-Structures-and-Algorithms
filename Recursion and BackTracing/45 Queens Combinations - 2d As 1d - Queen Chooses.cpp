//Link: https://nados.io/question/queens-combinations-2d-as-1d-queen-chooses?zen=true
#include<bits/stdc++.h>
using namespace std;
int n;
vector<vector<bool>> queen;

void combo(int lcno, int placed) {
   if(placed == n) {
      for(auto x: queen) {
         for(auto y: x) {
            cout << (y ? "q\t" : "-\t");
         }
         cout << endl;
      }
      cout << endl;
      return;
   }

   for(int i = lcno + 1; i < n * n; ++i) {
      int row = i / n;
      int col = i % n;

      queen[row][col] = 1;
      combo(i, placed + 1);
      queen[row][col] = 0;
   }
}

int main() {
   cin >> n;
   queen.resize(n, vector<bool> (n, 0));
   combo(-1, 0);
}