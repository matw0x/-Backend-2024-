#include <iostream>
#include <ctime>

const size_t sizeArray = 10;

void bubbleSort(int* pArray);

int main() {
    srand(time(nullptr));
    
    int array[sizeArray];
    for (size_t i = 0; i != sizeArray; ++i) {
        array[i] = rand() % 100;
    }

    auto printArray = [&]() {
        for (size_t i = 0; i != sizeArray; ++i) {
            std::cout << array[i] << ' ';
        }
        std::cout << '\n';
    };

    printArray();
    bubbleSort(array);
    printArray();


    return 0;
}

void bubbleSort(int* pArray) {
    for (size_t i = 0; i != sizeArray - 1; ++i) {
        for (size_t j = 0; j != sizeArray - i - 1; ++j) {
            if (pArray[j] > pArray[j + 1]) {
                std::swap(pArray[j], pArray[j + 1]);
            }
        }
    }
}