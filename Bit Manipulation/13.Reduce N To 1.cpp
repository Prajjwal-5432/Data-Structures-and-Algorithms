//Link: https://nados.io/question/reduce-n-to-1?zen=true

#include<bits/stdc++.h>
using namespace std;

int main(){
    long n;
    cin >> n;

    int res = 0;

    while(n != 1) {
        if(n % 2 == 0) n /= 2;
        else if(n == 3) {
            res += 2;
            break;
        } else if(n % 4 == 1) {
            n--;
        } else if(n % 4 == 3) {
            n++;
        }
        res++;
    }

    cout << res;
}