//Link: https://nados.io/question/remove-invalid-parenthesis?zen=true
#include<bits/stdc++.h>
using namespace std;
vector<int> arr, first, second;
vector<int> firsta, seconda;
int diff;
void solution(int idx, int n, int sum1, int sum2) {
    if(idx == n) {
        if(abs(sum1 - sum2) < diff) {
            diff = abs(sum1 - sum2);
            firsta = first, seconda = second;
        }
        return;
    }
    if(first.size() < (n + 1) / 2) {
        first.push_back(arr[idx]);
        solution(idx + 1, n, sum1 + arr[idx], sum2);
        first.pop_back();
    }
    if(second.size() < (n + 1) / 2) {
        second.push_back(arr[idx]);
        solution(idx + 1, n, sum1, sum2 + arr[idx]);
        second.pop_back();
    }
}
int main() {
    int n;
    cin >> n;
    arr.resize(n);
    diff = INT_MAX;
    
    for(auto &x: arr) cin >> x;
    solution(0, n, 0, 0);
    
    if(diff == INT_MAX) {
        cout << "-1";
    } else {
        cout << "[";
        for(int i = 0; i < firsta.size(); ++i) {
            cout << firsta[i];
            if(i != firsta.size() - 1) cout << ", ";
        }
        cout << "] [";
        for(int i = 0; i < seconda.size(); ++i) {
            cout << seconda[i];
            if(i != seconda.size() - 1) cout << ", ";
        }
        cout << "]";
    }
}