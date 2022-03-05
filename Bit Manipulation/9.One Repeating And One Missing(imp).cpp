//Link: https://nados.io/question/one-repeating-and-one-missing?zen=true

#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);

    int xor_ = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        xor_ ^= a[i] ^ (i + 1);
    }

    int rsb = xor_ & (-xor_);

    int x = 0, y = 0;
    
    for(int i = 0; i < n; ++i) {
        if((a[i] & rsb) == 0) x ^= a[i];
        else y ^= a[i]; 

        if((i + 1) & rsb == 0) x ^= (i + 1);
        else y ^= (i + 1);
    }

    for(auto val: a) {
        if(val == x) {
            cout << "Missing Number -> " << y << endl;
            cout << "Repeating Number -> " << x;
            break;
        } else if(val == y) {
            cout << "Missing Number -> " << x << endl;
            cout << "Repeating Number -> " << y;
            break;
        }
    }
}