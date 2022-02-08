//Link: https://nados.io/question/get-subsequence?zen=true
vector<string> gss(string s) {
    if(s.empty()) {
        return vector<string> ({""});
    }
    vector<string> v = gss(s.substr(1)), ans;

    for(auto &x: v) {
        ans.push_back(x);
        x.insert(x.begin(), s[0]);
        ans.push_back(x);
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string s;
    cin >> s;
    vector<string> ans = gss(s);
    int cnt = 0;

    cout << "[";
    for (string str : ans) {
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << "]";
}
