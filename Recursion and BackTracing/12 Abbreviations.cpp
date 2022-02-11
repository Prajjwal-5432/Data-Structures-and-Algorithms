//Link: https://nados.io/question/abbreviation-using-backtracking?zen=true
//Time: O(2^n)
#include<iostream>
using namespace std;
void solution(string str, string asf,int count, int pos) {
    if(pos == str.length()) {
        cout << asf << (count ? to_string(count) : "") << "\n";
        return;
    }

    solution(str, asf + (count ? to_string(count) : "") + str[pos], 0, pos + 1);
    solution(str, asf, count + 1, pos + 1);
}
int main() {
    string str;
    cin >> str;
    solution(str,"",0,0);
    return 0;
}