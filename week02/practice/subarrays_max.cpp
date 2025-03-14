#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxOfSubarray(vector<int> list, int k) {
    vector<int> res;
    deque<int> d;
    d.push_back(0);
    for (int i = 1; i < k; i++) {
        while (!d.empty() && list[i] >= list[d.back()])
            d.pop_back();
        d.push_back(i);
    }
    res.push_back(list[d.front()]);
    
    for (int i = k; i < list.size(); i++) {
        while (!d.empty() && d.front() <= (i-3))
            d.pop_front();
        while (!d.empty() && list[i] >= list[d.back()]) 
            d.pop_back();
        d.push_back(i);
        res.push_back(list[d.front()]);
    }
    return res;
}

int main(int argc, char* argv[]) {
    if (argc > 2) {
        vector<int> in;
        for (int i = 1; i < argc-1; i++)
            in.push_back(atoi(argv[i]));

        vector<int> res = maxOfSubarray(in, atoi(argv[argc-1]));
        for (int e : res) cout << e << " ";
        cout << endl;
    }
}