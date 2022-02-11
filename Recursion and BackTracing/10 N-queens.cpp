//Link: https://nados.io/question/n-queens?zen=true
//Time: O(n!)
int n;
vector<vector<int>> chess;
vector<array<int, 2>> queen;
vector<int> row, col;

bool canPlace(int r, int c) {
  bool flag = 0;

  flag |= row[r];
  flag |= col[c];
  for(auto x : queen) flag |= (abs(x[0] - r) == abs(x[1] - c));

  return !flag;
}

void printNQueens(string qsf, int r){
    if(r == n) {
      cout << qsf << ".\n";
      return; 
    }

    for(int i = 0; i < n; ++i) {
      if(canPlace(r, i)) {
        row[r] = col[i] = 1;
        queen.push_back({r, i});
        printNQueens(qsf + to_string(r) + "-" + to_string(i) + ", ", r + 1);
        queen.pop_back();
        row[r] = col[i] = 0;
      }
    }
    
}
