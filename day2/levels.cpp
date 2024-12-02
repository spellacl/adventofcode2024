#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>

int main(int argc, char * argv[])
{
    std::vector<int> first, second;

    int answer = 0;
    for(std::string line; std::getline(std::cin, line);)
    {
        std::istringstream iss(line);
        std::string value;

        bool increasing = true;
        bool decreasing = true;
        bool adjacent_123 = true;

        std::getline(iss, value, ' ');
        int last_value = std::stoi(value);

        bool safe = true;
        while(std::getline(iss, value, ' '))
        {
            int this_value = std::stoi(value);
            increasing = increasing & (last_value < this_value);
            decreasing = decreasing & (last_value > this_value);

            int difference = std::abs(this_value - last_value);
            adjacent_123 = difference >= 1 && difference <= 3;
            
            if( (!increasing && !decreasing) || !adjacent_123)
            {
                safe = false;
                break;
            }
            last_value = this_value;
        }
        if(safe) answer++;
    }
    std::cout << "answer " << answer << std::endl;

    return 0;
}
