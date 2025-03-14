#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

bool one_away(const string &s1, const string &s2) {
    int diff = s1.length() - s2.length();
    if (diff == 0) {
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) diff++;
        }
        if (diff > 1) return false;
    } else if (diff == 1) {
        int i = 0, j = 0;
        while (j < s2.length()) {
            if (i >= s1.length()) return false;
            if (s1[i++] != s2[j++]) j--;
        }
    } else if (diff = -1) {
        int i = 0, j = 0;
        while (i < s1.length()) {
            if (j >= s2.length()) return false;
            if (s1[i++] != s2[j++]) i--;
        }
    } else return false;
    return true;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (one_away(s1, s2)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    return 0;
}
