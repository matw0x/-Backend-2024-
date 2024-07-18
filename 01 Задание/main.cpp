#include <iostream>
#include <ctime>
#include <vector>

void bubbleSort(std::vector<int>&);

int main() {
    std::vector<int> data(10);

    srand(time(nullptr));
    for (size_t i = 0; i != data.size(); ++i) {
        data[i] = rand() % 100;
    }

    auto printArray = [&]() {
        for (size_t i = 0; i != data.size(); ++i) {
            std::cout << data[i] << ' ';
        }
        std::cout << '\n';
    };

    printArray();
    bubbleSort(data);
    printArray();

    return 0;
}

void bubbleSort(std::vector<int>& data) {
    for (size_t i = 0; i != data.size() - 1; ++i) {
        for (size_t j = 0; j != data.size() - i - 1; ++j) {
            if (data[j] > data[j + 1]) {
                std::swap(data[j], data[j + 1]);
            }
        }
    }
}