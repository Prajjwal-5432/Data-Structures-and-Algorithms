//Link: https://nados.io/question/print-encodings?zen=true
//Time: O(n!)
void printEncoding(string str, string asf){
    if(str.length() == 0) {
        cout << asf << "\n";
        return;
    } else if(str.length() == 1) {
        if(str[0] == '0') return;
        cout << asf << char('a' + str[0] - '0' - 1) << "\n";
        return;
    } else {
        if(str[0] == '0') return;
        else printEncoding(str.substr(1), asf + char('a' + str[0] - '0' - 1));
        
        string s = str.substr(0, 2);
        if(stoi(s) <= 26) {
            return printEncoding(str.substr(2), asf + char('a' + stoi(s) - 1));
        }
    }
}