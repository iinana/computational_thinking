#include <iostream>
#include <string>
using namespace std;

// O(n) time, O(1) space
// string string_compression(string s) {
//     string res = "";
//     int count = 1;
//     for (int i = 0; i < s.length(); i++) {
//         if (s[i] != s[i+1]) {
//             res += s[i];
//             res += ('0' + count);
//             count = 1;
//         } else count++;
//     }
//     if (res.length() >= s.length()) return s;
//     else return res;
// }

// O(n) time, O(n) space
// 교수님 풀이
string string_compression(string s) {
    if (s.length() == 0)
        return s;

    string res = "";
    char prev = s[0];
    int cnt = 1;
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == prev) {
            cnt++;
        } else {
            res += prev;
            res += to_string(cnt);
            prev = s[i];
            cnt = 1;
        }
    }
    res += prev;
    res += to_string(cnt);

    if (s.length() <= res.length())
        return s;
    else return res;
}

int main() {
    cout << string_compression("abbcccccaaa") << endl;  // a2b1c5a3
    cout << string_compression("aabaaa") << endl;   // aabaaa
}