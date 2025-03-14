#include <iostream>
using namespace std;

int num_bits_to_flip(int a, int b) {
    int diff = a^b;
    int to_bit = 1;

    while (diff / to_bit >= 1) to_bit *= 2;
    int count = 0;
    for (; to_bit > 0; to_bit /= 2) {
        if (diff >= to_bit) {
            diff -= to_bit;
            count++;
        }
        if (diff <= 0) break;
    }
    return count;
}

int main() {
    int a = 29;
    int b = 15;

    int output = num_bits_to_flip(a, b);
    cout << output << endl;
    
    return 0;
    // The output for the above example is 2.
}
