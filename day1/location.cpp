#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>

int main(int argc, char * argv[])
{
    std::vector<int> first, second;

    for(std::string line; std::getline(std::cin, line);)
    {
        std::istringstream iss(line);
        std::string value;

        std::getline(iss, value, ' ');
        first.push_back(std::stoi(value));
        std::getline(iss, value, '\n');
        second.push_back(std::stoi(value));
    }

    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());

    std::vector<int> result;
    std::transform(first.begin(), first.end(), second.begin(), std::back_inserter(result),
                   [](int& a, int& b)
                   {
                        return std::abs(a-b);
                   });
    auto answer = std::accumulate(result.begin(), result.end(), 0, std::plus<int>{});
    std::cout << answer << std::endl;

    // Part 2
    int answer2 = 0;
    for(auto cit = first.cbegin(); cit != first.cend(); cit++)
    {
        int current = *cit;
        answer2 += current * std::count(second.begin(), second.end(), current);
    }
    std::cout << answer2 << std::endl;

    return 0;
}
