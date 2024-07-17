#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

void randomize(std::vector<int>& arr);
void sort(std::vector<int>& A, const std::vector<int>& B);

int main() {
    std::vector<int> A, B;

    A = { 2, 4, 1, 3, 2, 4, 6, 7, 9, 2, 19 };
    B = { 2, 1, 4, 3, 6, 9 };

    auto print = [](const std::vector<int>& arr) { 
        for (size_t i = 0; i != arr.size(); ++i) {
            std::cout << arr[i] << " ";
    }
        std::cout << '\n';
    };

    print(A);
    print(B);
    sort(A, B);
    print(A);

    return 0;
}

void sort(std::vector<int>& A, const std::vector<int>& B) {
    std::unordered_map<int, int> dict; // num in B : count this num in A
    for (const int& elementB : B) {
        dict.insert({ elementB, 0 });
    }

    std::vector<int> remainings;

    for (const int& elementA : A) {
        if (std::find(B.begin(), B.end(), elementA) != B.end()) ++dict[elementA];
        else remainings.push_back(elementA);
    }

    std::vector<int> answer;
    for (const int& elementB : B) {
        for (int i = 0; i != dict[elementB]; ++i) {
            answer.push_back(elementB);
        }
    }

    std::sort(remainings.rbegin(), remainings.rend());
    for (size_t i = 0; i != remainings.size(); ++i) {
        answer.push_back(remainings[i]);
    }

    A = std::move(answer);
}