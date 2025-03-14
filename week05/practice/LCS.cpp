#include <iostream>
#include <vector>
using namespace std;

string print_LCS(vector<vector<char>> arrow, string s, int i, int j, string& res) {
    if (i <= 0 || j <= 0) return res;

    if (arrow[i][j] == 'd') {
        print_LCS(arrow, s, i - 1, j - 1, res);
        res += s[i - 1];
    } else if (arrow[i][j] == 'u') {
        print_LCS(arrow, s, i - 1, j, res);
    } else print_LCS(arrow, s, i, j - 1, res);
    return res;
}

string LCS(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    vector<vector<int>> len(m+1, vector<int>(n+1, 0));
    vector<vector<char>> arrow(m+1, vector<char>(n+1, 0));
    for (int i = 0; i < m; i++)
        len[i][0] = 0;
    for (int j = 0; j < n; j++)
        len[0][j] = 0;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i-1] == s2[j-1]) {
                len[i][j] = len[i-1][j-1] + 1;
                arrow[i][j] = 'd'; // diagonal as 'd'
            } else if (len[i-1][j] > len[i][j-1]) {
                len[i][j] = len[i-1][j];
                arrow[i][j] = 'u'; // up as 'u'
            } else {
                len[i][j] = len[i][j-1];
                arrow[i][j] = 'l'; // left as 'l'
            }
        }
    }

    string res = "";
    return print_LCS(arrow, s1, m, n, res);
}

int main() {
    string s1 = "THEIR";
    string s2 = "HABIT";
    cout << LCS(s1, s2) << endl;
}