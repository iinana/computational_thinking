#include <iostream>
#include <unordered_map>
using namespace std;

class SparseArray {
    unordered_map<int, int> map;
    int size;

    public:
        SparseArray(int* nums, int size);

        bool checkIndex(int i);
        void set(int i, int val);
        int get(int i);
};

SparseArray::SparseArray(int* nums, int s) : size(s) {
    for (int i = 0; i < s; i++) {
        if (nums[i] != 0)
            map.insert(make_pair(i, nums[i]));
    }
}
bool SparseArray::checkIndex(int i) {
    if (i < 0 || i >= size) return false;
    else return true;
}
void SparseArray::set(int i, int val) {
    if (!checkIndex(i)) {
        cout << "[Error/set] out of bound" << endl;
        return;
    }

    if (val != 0) map[i] = val;
    else map.erase(i);
}
int SparseArray::get(int i) {
    if (checkIndex(i)) {
        if (map.count(i) > 0) return map.at(i);
        else return 0;
    }
    else {
        cout << "[Error/set] out of bound" << endl;
        return -1;
    }
}

int main() {
    int N = 1000;
    int *input = new int[N];

    for (int i = 0; i < N; i++) {
        if (i % 100 == 0) input[i] = 1; 
        else input[i] = 0;
    }
    SparseArray A(input, N);

    int v = A.get(100);
    cout << v << endl; // 1
    v = A.get(6);
    cout << v << endl; // 0
    A.set(6, 2);
    v = A.get(6);
    cout << v << endl; // 2
    A.set(100, 4);
    v = A.get(100);
    cout << v << endl; // 4
    v = A.get(N);
    cout << v << endl;

    delete[] input;
}