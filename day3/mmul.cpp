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
    bool do_mmul = true;
    for(std::string line; std::getline(std::cin, line);)
    {
        std::regex mul_regex("mul\\(\\d{1,3},\\d{1,3}\\)");
        std::regex part2("mul\\(\\d{1,3},\\d{1,3}\\)|do\\(\\)|don't\\(\\)");
        
        //auto mult_start = std::sregex_iterator(line.begin(), line.end(), mul_regex);
        auto mult_start = std::sregex_iterator(line.begin(), line.end(), part2);
        auto mult_end = std::sregex_iterator();

        for(auto it = mult_start; it != mult_end; it++)
        {
            std::string curr = (*it).str();

            if(curr == std::string("don't()"))
                do_mmul = false;
            else if(curr == std::string("do()"))
                do_mmul = true;
            else if(do_mmul)
            {
                std::smatch numbers;
                std::regex num_regex("mul\\((\\d{1,3}),(\\d{1,3})\\)");
                if(std::regex_match(curr, numbers, num_regex))
                {
                    answer += std::stoi(numbers[1].str()) * std::stoi(numbers[2].str());
                }
            }
        }
    }
    std::cout << answer << std::endl;

    return 0;
}
