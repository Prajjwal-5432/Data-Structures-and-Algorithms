//Link: https://nados.io/question/print-value-of-rsb-mask?zen=true

#include<bits/stdc++.h>
using namespace std;
void decToBin(unsigned int n) {
    if(n / 2 != 0) {
        decToBin(n / 2);
    }
    cout << n % 2;
}
int main(){
    
    
    int n;
    cin >> n;
    decToBin(n & -n);
}