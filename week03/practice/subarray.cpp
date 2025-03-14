#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// vector<int> maximum_of_subarrays(int k, vector<int>& array) {
//     deque<int> max_idx;
//     vector<int> out;

//     for (int i = 0; i < array.size(); i++) {
//         if (max_idx.empty()) max_idx.push_back(i);
//         else if (max_idx.size() == 1) {
//             if (array[i] > array[max_idx.front()])
//                 max_idx.push_back(i);
//             else max_idx.push_front(i);
//         } else if (array[i] > array[max_idx.back()]) {
//             max_idx.pop_front();
//             max_idx.push_back(i);
//         } else if (array[i] > array[max_idx.front()]) {
//             max_idx.pop_front();
//             max_idx.push_front(i);
//         }
        
//         if (i >= (k - 1)) {
//             out.push_back(array[max_idx.back()]);
//             if (max_idx.front() <= (i - k + 1)) max_idx.pop_front();
//             if (max_idx.back() <= (i - k + 1)) max_idx.pop_back();
//         }
//     }

//     return out;
// }

vector<int> maximum_of_subarrays(int k, vector<int>& array) {
    deque<int> idxs;
    vector<int> out;

    for (int i = 0; i < k; i++) {
        while (!idxs.empty() && array[idxs.back()] <= array[i])
            idxs.pop_back();
        idxs.push_back(i);
    }
    out.push_back(array[idxs.front()]);

    for (int i = k; i < array.size(); i++) {
        while (!idxs.empty() && idxs.front() <= (i - k))
            idxs.pop_back();
        while (!idxs.empty() && array[idxs.back()] <= array[i])
            idxs.pop_back();
        idxs.push_back(i);
        out.push_back(array[idxs.front()]);
    }

    return out;
}

int main() {
    vector<int> array = {10, 5, 2, 7, 8, 7};
    int k = 3;

    vector<int> res = maximum_of_subarrays(k, array);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}