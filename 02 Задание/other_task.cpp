#include <unordered_map>
#include <vector>
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>
#include <utility>

bool readFile(const std::string&, std::unordered_map<std::string, int>&, std::vector<std::pair<std::string, int>>&);
void countWords(std::ifstream&, std::unordered_map<std::string, int>&, std::vector<std::pair<std::string, int>>&);

int main() {
    const std::string path = "test.txt";
    std::unordered_map<std::string, int> dataFromFile;
    std::vector<std::pair<std::string, int>> answer;

    auto print = [&answer]() {
        for (auto const& pair : answer) {
            std::cout << pair.first << " : " << pair.second << '\n';
        }
        std::cout << '\n';
    };

    if (readFile(path, dataFromFile, answer)) {
        print();
    } else {
        std::cout << "Error\n";
    }

    return 0;
}

bool readFile(const std::string& pathToFile, std::unordered_map<std::string, int>& dataFromFile, std::vector<std::pair<std::string, int>>& result) {
    std::ifstream file(pathToFile);

    if (file && file.is_open() && file.peek() != std::ifstream::traits_type::eof()) {
        countWords(file, dataFromFile, result);
        return true;
    }

    return false;
}

void countWords(std::ifstream& file, std::unordered_map<std::string, int>& dataFromFile, std::vector<std::pair<std::string, int>>& modelMap) {
    std::string word;
    while (file >> word) {
        ++dataFromFile[word];
    }

    for (auto const& elementMap : dataFromFile) {
        modelMap.push_back({ elementMap.first, elementMap.second });
    }

    std::sort(modelMap.begin(), modelMap.end(),
    [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) { 
        if (a.second == b.second) {
            return a.first > b.first;
       }
       return a.second > b.second;
    });
}