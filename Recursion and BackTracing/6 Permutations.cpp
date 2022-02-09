//Link: https://nados.io/question/print-permutations
//Time complexity: O(n!)
void printPermutations(string str, string asf){
    if(str.empty()) {
        cout << asf << "\n";
        return;
    }
    for(int i = 0; i < str.length(); ++i) {
        printPermutations(str.substr(0, i) + str.substr(i + 1), asf + str[i]);
    }
}