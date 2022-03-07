//Link: https://nados.io/question/all-repeating-three-times-except-one?zen=true
//Refer: https://medium.com/pranayaggarwal25/find-the-element-that-appears-once-in-array-but-other-elements-appear-thrice-663066d5cf9

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int ones = 0, twos = 0;

    for(int i = 0, x; i < n; ++i) {
        cin >> x;
        twos |= ones & x;
        ones ^= x;
        int threes = ~(ones & twos);
        ones &= threes;
        twos &= threes;
    }

    cout << ones;
}