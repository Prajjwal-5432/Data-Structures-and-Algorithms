//Link: https://nados.io/question/all-repeating-except-two?zen=true
//Refer: https://www.youtube.com/watch?v=pnx5JA9LNM4&list=PL-Jc9J83PIiFJRioti3ZV7QabwoJK6eKe&index=9

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);

    int ans = 0;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        ans ^= a[i];
    }

    int rsb = (ans & -ans);

    int x = 0, y = 0;

    for(int i = 0; i < n; ++i) {
        if((a[i] & rsb) == 0) x ^= a[i];
        else y ^= a[i];
    }

    cout << min(x, y) << endl << max(x, y);
}