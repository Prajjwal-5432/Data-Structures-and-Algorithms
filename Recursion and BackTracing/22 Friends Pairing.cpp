//Link: https://nados.io/question/friends-pairing-2?zen=true
#include<bits/stdc++.h>
using namespace std;

int n, cnt;
vector<bool> used;

void getCombo(int num, string asf) {
    if(num == n + 1) {
        cout << ++cnt << "." << asf << "\n";
        return;
    }

    if(used[num]) getCombo(num + 1, asf);
    else {
        used[num] = 1;
        getCombo(num + 1, asf + "(" + to_string(num) + ") ");
        for(int i = 1; i < n + 1; ++i) {
            if(!used[i]) {
                used[i] = 1;
                getCombo(num + 1, asf + "(" + to_string(num) + "," + to_string(i) + ") ");
                used[i] = 0;
            }
        }
        used[num] = 0;
    }
}
int main() {
    cin >> n;
    used.resize(n + 1, 0);
    getCombo(1, "");
}