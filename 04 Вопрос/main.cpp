#include <iostream>
#include <vector>
#include <algorithm>

int binarySearch(const std::vector<int>& arr, int element);

int main() {
    std::vector<int> arr = { 1, 1, 1, 2, 1, 1, 0 };

    if (arr.empty()) {
        std::cout << "Error\n";
        return -1;
    }

    std::sort(arr.begin(), arr.end());
    std::cout << binarySearch(arr, 0);

    return 0;
}

int binarySearch(const std::vector<int>& arr, int element) {
    int left = 0, right = arr.size() - 1, index = -1;
    while (true) {
        if (left > right) break;
        int middle = (left + right) / 2;

        if (element < arr[middle]) right = middle - 1;
        else if (element > arr[middle]) left = middle + 1;
        else return middle; 
    }

    return index;
}