#include <iostream>
#include <string>
#include <map>
#include <sstream>
#include <algorithm>

int main() {
    int part1{}, part2{};
    int game{1};
    for (std::string line; std::getline(std::cin, line); ++game) {
        std::istringstream iss(line); 
        iss.ignore(7, ':');
        int value;
        std::string color;
        std::map<char, int> counter;
        while (iss >> value >> color) {
            counter[color.front()] = std::max(counter[color.front()], value);
        }

        bool valid = counter['r'] <= 12 and counter['g'] <= 13 and counter['b'] <= 14;
        part1 += valid ? game : 0;
        part2 += counter['r'] * counter['g'] * counter['b'];
    }

    std::cout << part1 << "\n";
    std::cout << part2 << "\n";
}
