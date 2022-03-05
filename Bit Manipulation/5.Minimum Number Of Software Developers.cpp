//Link: https://nados.io/question/minimum-number-of-software-developers?zen=true

#include<bits/stdc++.h>
using namespace std;
vector<int> sol;

void solution(vector<int> people, int nskils, int cp, vector<int> onesol, int smask){
    if(cp == people.size()) {
        if(smask == (1 << nskils) - 1) {
            if(sol.empty() or onesol.size() < sol.size()) sol = onesol;
        }    
        return;
    }
    solution(people, nskils, cp + 1, onesol, smask);
    onesol.push_back(cp);
    solution(people, nskils, cp + 1, onesol, (smask | people[cp]));
    onesol.pop_back();
}


int main(){
    int n;
    cin >> n;

    unordered_map<string, int> smap;
    for(int i = 0; i < n; i++){
        string x;
        cin >> x;
        smap[x] = i;
    }
    int np;
    cin >> np;

    vector<int> people(np);

    for(int i = 0; i < np; i++){
        int personskills;
        cin >> personskills;

        for(int j = 0; j < personskills; j++){
            string skill;
            cin >> skill;

            int snum = smap[skill];
            people[i] = people[i] | (1 << snum);
        }
    }

    solution(people, n, 0, vector<int> (), 0);
    cout << "[";
    for(int i = 0; i < sol.size() - 1; ++i) {
        cout << sol[i] << ", ";
    }
    cout << sol.back() << "]";   

}