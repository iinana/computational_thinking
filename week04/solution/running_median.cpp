#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<double> running_median(vector<int>& nums) {
    priority_queue<int> left; // max queue
    priority_queue<int> right; // min queue
    vector<double> output;
    priority_queue<int>* toput;
    priority_queue<int>* notput;

    double median = 0;
    for (int num : nums) {
        bool inversed = false;
        if (num > median) {
            toput = &right;
            notput = &left;
            num = -num;
            inversed = true;
        } else {
            toput = &left;
            notput = &right;
        }

        int len_toput = toput->size();
        int len_notput = notput->size();
        if (len_toput == len_notput) {
            toput->push(num);
            median = (inversed) ? -toput->top() : toput->top();
        } else if (len_toput > len_notput) {
            int temp = toput->top();
            toput->pop();
            notput->push(-temp);
            toput->push(num);
            median = (toput->top() - notput->top()) / 2.0;
            if (inversed) median = -median;
        } else {
            toput->push(num);
            median = (toput->top() - notput->top()) / 2.0;
            if (inversed) median = -median;
        }
        output.push_back(median);
    }
    return output;
}

int main() {
    vector<int> nums = {2, 1, 5, 7, 2, 0, 5};

    vector<double> n = running_median(nums);

    for (double med : n) {
        cout << med << " ";
    }
    cout << endl;

    return 0;
    // The output n for the above example is 2 1.5 2 3.5 2 2 2.
}
