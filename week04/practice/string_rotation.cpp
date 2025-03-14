#include <iostream>
#include <string.h>
using namespace std;

// s1이 s2의 substring인지 확인
bool isSubstring(string s1, string s2) {
    return (s2.find(s1) != string::npos);
}

// improve it as O(1) space (now O(n) space)
// bool string_rotation(string s1, string s2) {
//     int front = s2.find(s1.front());
//     if (front == string::npos)
//         return false;
    
//     string sub1 = s2.substr(0, front - 1);
//     if (!isSubstring(sub1, s1))
//         return false;
//     string sub2 = s2.substr(front, s2.length());
//     if (!isSubstring(sub2, s1))
//         return false;
//     return true;
// }

bool string_rotation(string s1, string s2) {
    s1 += s1;
    return isSubstring(s2, s1);
}

int main() {
    cout << ((string_rotation("waterbottle", "erbottlewat")) ? "true" : "false") << endl;
    cout << ((string_rotation("abc", "bac")) ? "true" : "false") << endl;
}