//Link: https://nados.io/question/k-subsets-with-equal-sum?zen=true
#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int sum, n, k;
vector<vector<int>> subsets;

void ksubset(int idx) {
	if(idx == v.size()) {
		if(!subsets.back().empty()) {
			bool flag = 1;
			for(auto x: subsets) flag &= sum == accumulate(x.begin(), x.end(), 0);
			if(flag) {
				for(auto x: subsets) {
					cout << "[";
					for(int i = 0; i < x.size(); ++i) {
						cout << x[i] << (i == x.size() - 1 ? "" : ", ");
					}
					cout << "] ";
				}
				cout << endl;
			}
		}
		return;
	}

	for(int i = 0; i < k; ++i) {
		subsets[i].push_back(v[idx]);
		ksubset(idx + 1);
		subsets[i].pop_back();
		if(subsets[i].empty()) break;
	}
}
int main() {
	cin >> n;

	v.resize(n);

	for(auto &x: v) {
		cin >> x;
		sum += x;
	}

	cin >> k;

	if(sum % k != 0) return cout << -1, 0;
	sum /= k;

	subsets.resize(k, vector<int>());
	ksubset(0);
}