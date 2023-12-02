import std;

int main() {
    int part1{}, part2{}, value, game{1};
    for (std::string line, color; std::getline(std::cin, line); ++game) {
        std::map<char, int> counter;
        std::istringstream iss(line); 
        for (iss.ignore(7, ':'); iss >> value >> color;) {
            counter[color.front()] = std::max(counter[color.front()], value);
        }

        part1 += counter['r'] <= 12 and counter['g'] <= 13 and counter['b'] <= 14 ? game : 0;
        part2 += counter['r'] * counter['g'] * counter['b'];
    }

    std::cout << part1 << "\n";
    std::cout << part2 << "\n";
}
