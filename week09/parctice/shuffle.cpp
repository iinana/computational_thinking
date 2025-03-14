#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

vector<char> fisher_yates_shuffle(vector<char> v) {
    int n = v.size();
    for (int i = 0; i < n-1; i++) {
        int j = rand() % (n - i) + i;
        char temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
    return v;
}

int main() {
    srand(time(0));
    vector<char> v = {'a', 'b', 'c', 'd', 'e'};
    vector<char> res = fisher_yates_shuffle(v);
    for (char c : res) cout << c << " ";
    cout << endl;
}