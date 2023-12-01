import std;
#define PART2

auto calibration_value(std::string str) {
    static const std::vector<std::string> strdigs = {
        "1", "2", "3", "4", "5", "6", "7", "8", "9"
#ifdef PART2
        , "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
#endif
    };

    std::pair<std::size_t, int> first{ std::string::npos, 0 }, last{ 1, 0 };
    for (const auto [i, strdig] : std::views::enumerate(strdigs)) {
        first = std::min({     str. find(strdig), 1 + i % 9 }, first );
        last  = std::max({ 1 + str.rfind(strdig), 1 + i % 9 }, last  );
    }
    return first.second * 10 + last.second;
}

int main() {
    std::cout << std::ranges::fold_left(std::views::istream<std::string>(std::cin)
        | std::views::transform(calibrate), 0, std::plus{});
}
