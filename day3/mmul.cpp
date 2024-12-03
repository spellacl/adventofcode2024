#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <regex>

int main(int argc, char * argv[])
{
    std::vector<int> first, second;

    int answer = 0;
    for(std::string line; std::getline(std::cin, line);)
    {
        std::regex mul_regex("mul\\(\\d{1,3},\\d{1,3}\\)");
        
        auto mult_start = std::sregex_iterator(line.begin(), line.end(), mul_regex);
        auto mult_end = std::sregex_iterator();

        for(auto it = mult_start; it != mult_end; it++)
        {
            std::string mmul = (*it).str();
            std::smatch numbers;
            std::regex num_regex("mul\\((\\d{1,3}),(\\d{1,3})\\)");
            if(std::regex_match(mmul, numbers, num_regex))
            {
                answer += std::stoi(numbers[1].str()) * std::stoi(numbers[2].str());
            }
        }
    }
    std::cout << answer << std::endl;

    return 0;
}
