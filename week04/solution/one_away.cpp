#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

bool one_away(const string &s1, const string &s2) {
    string shorter, longer;
    if (s1.length() <= s2.length()) {
        shorter = s1;
        longer = s2;
    } else {
        shorter = s2;
        longer = s1;
    }

    int s_len = shorter.length();
    int l_len = longer.length();
    if (s_len == l_len) {
        bool oneEdit = false;
        for (int i = 0; i < s_len; i++) {
            if (shorter[i] != longer[i]) {
                if (oneEdit) return false;
                else oneEdit = true;
            }
        }
        return true;
    } else if (s_len + 1 == l_len) {
        int i = 0, j = 0;
        bool oneEdit = false;
        while (i < s_len && j < l_len) {
            if (shorter[i] == longer[j]) {
                i++;
                j++;
            } else {
                if (oneEdit) return false;
                else {
                    oneEdit = true;
                    j++;
                }
            }
        }
        return true;
    } else return false;
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
