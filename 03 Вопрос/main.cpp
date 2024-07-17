#include <iostream>
#include <vector>

int maxSum(const std::vector<int>& array);

int main() {
    std::vector<int> arr = { 2, 7, 4, 1, 8 };

    if (arr.size() < 2) {
        std::cout << "err\n";
        return -1;
    }

    std::cout << maxSum(arr);

    return 0;
}

int maxSum(const std::vector<int>& array) {
    int max = array[0], otherMax = array[1];
    for (size_t i = 2; i != array.size(); ++i) {
        if (array[i] > max) {
            if (max > otherMax) otherMax = max;
            max = array[i];
        } else if (array[i] > otherMax) {
            if (otherMax > max) max = otherMax;
            otherMax = array[i];
        }
    }

    return max + otherMax;
}