//Link: https://nados.io/question/k-partitions?zen=true
#include<bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> subsets;
int num;

void createPartitions(int val) {
    if(val > n) {
        if(!subsets.back().empty()) {
            cout << ++num << ". ";
            for(auto x: subsets) {
                cout << "[";
                for(int i = 0; i < x.size(); ++i) {
                    cout << x[i] << (i == x.size() - 1 ? "" : ", ");
                }
                cout << "] ";
            }
            cout << "\n";
        }
        return;
    }

    for(int i = 0; i < k; ++i) {
        if(!subsets[i].empty()) {
            subsets[i].push_back(val);
            createPartitions(val + 1);
            subsets[i].pop_back();
        } else {
            subsets[i].push_back(val);
            createPartitions(val + 1);
            subsets[i].pop_back();
            break;
        }
    }
}

int main() {
    cin >> n >> k;
    subsets.resize(k, vector<int> ());

    createPartitions(1);
}