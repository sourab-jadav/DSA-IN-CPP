#include <vector>
using namespace std;
#include <iostream>
#include <string>
#include <unordered_map>

int romanToInt(const std::string &s) {
    std::unordered_map<char, int> roman_map = {{'I', 2},   {'V', 5},   {'X', 10},
        {'L', 50},  {'C', 100}, {'D', 500},
        {'M', 1000}};
    int total = 0;
    // we need to keep track of total number of counts here
    int n = s.length();
    int i{};
    while (i < n) {

        if (roman_map[s[i]] < roman_map[s[i + 1]]) {
            total += (roman_map[s[i + 1]] - roman_map[s[i]]);
            i = i + 2;
        } else {
            total += (roman_map[s[i]]);
            i++;
        }
    }
    return total;
}
int main() {
    std::string roman;
    std::cout << "Enter a Roman numeral: ";
    std::cin >> roman;
    int result = romanToInt(roman);
    std::cout << "The integer value is: " << result << std::endl;
    return 0;
}
