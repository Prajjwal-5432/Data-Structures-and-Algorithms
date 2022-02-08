//Link: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution {
public:
    unordered_map<char, vector<char>> mp;
    string digits;
    vector<string> ans;
    
    void go(int idx, string asf) {
        if(idx == digits.length()) {
            ans.push_back(asf);
            return;
        }
        for(int i = 0; i < mp[digits[idx]].size(); ++i) {
            go(idx + 1, asf + mp[digits[idx]][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return vector<string> ();
        
        this->digits = digits;
        char x = 'a';
        for(char i = '2'; i < '7'; ++i) mp[i] = {x++, x++, x++};
        
        mp['7'] = {x++, x++, x++, x++};
        mp['8'] = {x++, x++, x++};
        mp['9'] = {x++, x++, x++, x++};
        
        go(0, "");
        
        return ans;
    }
};