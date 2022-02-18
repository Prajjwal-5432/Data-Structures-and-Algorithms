//Link: https://nados.io/question/words-k-length-words-1?zen=true
#include<bits/stdc++.h>
using namespace std;

void generateWords(int cc, string ustr,int ssf,int ts,vector<char>spots){
    if(cc == ustr.length()) {
        if(ssf == ts) {
            for(auto x: spots) cout << x;
            cout << endl;
        }
        return;
    }
    
    for(int i = 0; i < spots.size(); ++i) {
        if(spots[i] == '-') {
            spots[i] = ustr[cc];
            generateWords(cc + 1, ustr, ssf + 1, ts, spots);
            spots[i] = '-';
        }
    }
    generateWords(cc + 1, ustr, ssf, ts, spots);
}
int main(){
    string str;
    cin>>str;
    int k;
    cin>>k;
    set<char>unique;
    string ustr="";
    for(int i=0;i<str.length();i++){
        if(unique.find(str[i])==unique.end()){
            unique.insert(str[i]);
            ustr+=str[i];
        }
    }
    vector<char>spots(k, '-');
    generateWords(0,ustr,0,k,spots);
}