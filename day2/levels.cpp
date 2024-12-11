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

        std::vector<int> levels;
        while(std::getline(iss, value, ' '))
        {
            levels.push_back(std::stoi(value));
        }

        auto notSafe = [](int first, int second, bool &increasing, bool &decreasing)
            {
                increasing = increasing & (first < second);
                decreasing = decreasing & (first > second);

                int difference = std::abs(first - second);
                bool adjacent_123 = difference >= 1 && difference <= 3;
            
                return (!increasing && !decreasing) || !adjacent_123;
            };

        bool safe = true;
        bool increasing = true;
        bool decreasing = true;

        // part 1
        for(auto cit = levels.cbegin()+1; cit != levels.cend(); cit++)
        {
            if(notSafe( *(cit-1), *(cit), increasing, decreasing))
            {
                safe = false;
                break;
            }
        }
        if(safe) answer++;

        safe = true;
        increasing = true; decreasing = true;
        bool skipped = false;
        // a b c
        //   b c d
        for(auto cit = levels.cbegin()+2; cit != levels.cend(); cit++)
        {
            bool tmp_inreasing = increasing;
            bool tmp_decreaing = decreasing;
            bool firstNotSafe = notSafe(*(cit-2), *(cit-1), tmp_inreasing, tmp_decreaing);

            tmp_inreasing = increasing;
            tmp_decreaing = decreasing;
            bool secondNotSafe = notSafe(*(cit-1), *(cit), tmp_inreasing, tmp_decreaing);

            if(!
            
            tmp_inreasing = increasing;
            tmp_decreaing = decreasing;
            bool secondNotSafe = notSafe(*(cit-2), *(cit), tmp_inreasing, tmp_decreaing);
        }
    }
    std::cout << "answer " << answer << std::endl;

    return 0;
}
