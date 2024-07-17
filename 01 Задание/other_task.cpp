#include <iostream>
#include <string>
#include <stack>

bool bracketsCheck(const std::string& line);

int main() {
    std::string line;
    std::cin >> line;

    if (bracketsCheck(line)) std::cout << "Nice string\n";
    else std::cout << "Bad string\n";

    return 0;
}

bool bracketsCheck(const std::string& line) {
    std::stack<char> openBrackets;
    for (const char& symbol : line) {
        if (symbol == '(' || symbol == '{' || symbol == '[') {
            openBrackets.push(symbol);
        } else if (symbol == ')' || symbol == '}' || symbol == ']') {
            if (openBrackets.empty()) return false;
            char head = openBrackets.top();

            if (symbol != (head + head % 2 + 1)) return false;
            openBrackets.pop();
        }
    }

    return openBrackets.empty();
}