#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

void breakdown(string src, string res, vector<string>& lst) {
    if (src.length() <= 0) {
        lst.push_back(res);
        return;
    }

    for (int i = 0; i < src.length(); i++) {
        string temp = src;
        temp.erase(i, 1);
        breakdown(temp, res + src[i], lst);
    }
}

vector<string> permute(string& s) {
    vector<string> lst;
    breakdown(s, "", lst);
    return lst;
}

int main(int argc, char* argv[]) {
    string s(argv[1]);
    vector<string> out = permute(s);

    cout << "[ ";
    for (string s : out) {
        cout << "\"" << s << "\" ";
    }
    cout << "]" << endl;
}