#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

void fswap(string& a, int i, int j) {
    char temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void permute_rec(vector<string>& res, string a, int l, int r) {
    if (l == r) res.push_back(a);
    else {
        for (int i = l; i <= r; i++) {
            fswap(a, l, i);
            permute_rec(res, a, l+1, r);
            fswap(a, i, l);
        }
    }
}

vector<string> permute(string& s) {
    vector<string> res;
    permute_rec(res, s, 0, s.length()-1);
    return res;
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