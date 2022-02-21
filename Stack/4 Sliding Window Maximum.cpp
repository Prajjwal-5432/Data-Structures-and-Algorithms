//Link: https://nados.io/question/sliding-window-maximum?zen=true
#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for(auto &x: a) cin >> x;

	deque<int> q;

	int k;
	cin >> k;

	for(int i = 0; i < k - 1; ++i) {
		while(!q.empty() and q.back() < a[i]) q.pop_back();
		q.push_back(a[i]);
	}

	for(int i = 0; i < n - k + 1; ++i) {
		if(i and !q.empty() and q.front() == a[i - 1]) q.pop_front();
		while(!q.empty() and q.back() < a[i + k - 1]) q.pop_back();
		q.push_back(a[i + k - 1]);
		cout << q.front() << "\n"; 
	}
}