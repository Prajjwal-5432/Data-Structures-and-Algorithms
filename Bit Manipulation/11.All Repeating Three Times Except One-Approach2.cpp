//Link: https://nados.io/question/all-repeating-three-times-except-one?zen=true
//Refer: https://www.youtube.com/watch?v=3gJxLkPPW6M&list=PL-Jc9J83PIiFJRioti3ZV7QabwoJK6eKe&index=11

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int tn = INT_MAX, tn1 = 0, tn2 = 0;

    for(int i = 0, x; i < n; ++i) {
        cin >> x;

        int cwtn = tn & x;
        int cwtn1 = tn1 & x;
        int cwtn2 = tn2 & x;

        tn = tn & (~cwtn);
        tn1 = tn1 | cwtn;

        tn1 = tn1 & (~cwtn1);
        tn2 = tn2 | cwtn1;

        tn2 = tn2 & (~cwtn2);
        tn = tn | cwtn2;
    }

    cout << tn1;
}