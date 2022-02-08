//Link: https://nados.io/question/get-stair-paths?zen=true
vector<string> ans;
void go(int stairs, string asf) {
    if(stairs < 0) return;
    if(stairs == 0) {
        ans.push_back(asf);
        return;
    }
    go(stairs - 1, asf + string(1, '1'));
    go(stairs - 2, asf + string("2"));
    go(stairs - 3, asf + '3');
}

vector<string> get_stair_paths(int n) {
    go(n, "");
    return ans;
}

int main(){
    int n;
    cin >> n;
    vector<string> ans = get_stair_paths(n);
    int cnt = 0;

    cout << '[';
    for (string str : ans){
        if (cnt != ans.size() - 1)
            cout << str << ", ";
        else
            cout << str;
        cnt++;
    }
    cout << ']';
}