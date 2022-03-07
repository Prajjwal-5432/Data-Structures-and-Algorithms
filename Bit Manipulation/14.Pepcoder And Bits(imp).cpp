//Link: https://nados.io/question/pepcoder-and-bits?zen=true
//Refer: https://www.youtube.com/watch?v=DMTw6pP5zTg&list=PL-Jc9J83PIiFJRioti3ZV7QabwoJK6eKe&index=15

#include<bits/stdc++.h>
using namespace std;

long long ncr(long n, long r) {
    if(n < r) return 0LL;
    
    long long res = 1LL;
    
    for(long i = 0L; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    
    return res;
}

long long solution(long n, long k, int i) {
    if(i == 0) return 0;

    long long mask = (1L << i);
    
    if((n & mask) == 0) {
        return solution(n, k, i - 1);
    } else {
        return solution(n, k - 1, i - 1) + ncr(i, k);
    }
}

int main() {
    long n;
    cin >> n;
    
    long k = __builtin_popcountl(n);
    long long ans = solution(n, k, 63);
    cout << ans << "\n";
}