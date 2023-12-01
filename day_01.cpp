#include <iostream>
#include <algorithm>
#include <ranges>
#include <vector>
#include <string>
#define PART2

auto calibrate(std::string str) {
    static std::vector<std::string> strdigs = {
        "1", "2", "3", "4", "5", "6", "7", "8", "9"
#ifdef PART2
        , "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
#endif
    };

    using idx_val = std::pair<std::size_t, int>;
    idx_val first { std::string::npos, 0 };
    idx_val last  { 1, 0 };
    for (const auto [i, strdig] : std::views::enumerate(strdigs)) {
        int value = 1 + i % 9;
        first = std::min({     str. find(strdig), value }, first);
        last  = std::max({ 1 + str.rfind(strdig), value }, last );
    }

    return first.second * 10 + last.second;
}

int main() {
    auto calibration_values = std::views::istream<std::string>(std::cin)
        | std::views::transform(calibrate);
    std::cout << std::ranges::fold_left(calibration_values, 0, std::plus{});
}
