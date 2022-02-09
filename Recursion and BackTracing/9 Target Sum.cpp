//Link: https://nados.io/question/target-sum-subsets?zen=true
//Time: O(2^n)
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
int target;

void go(int idx, int target, string asf) {
  if(target < 0) return;
  if(idx == n) {
    if(target == 0) cout << asf << ".\n";
    return;
  }

  go(idx + 1, target - a[idx], asf + to_string(a[idx]) + ", ");
  go(idx + 1, target, asf);
}

int main(){
  cin >> n;
  a.resize(n);
  for(auto &x: a) cin >> x;
  cin >> target;

  go(0, target, "");
}