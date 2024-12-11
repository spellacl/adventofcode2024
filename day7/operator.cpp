#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <map>
#include <regex>
#include <set>
#include <cmath>

int main(int argc, char * argv[])
{
    std::vector<int> first, second;

    uint64_t answer = 0, answer2 = 0;
    std::regex num_regex("(\\d+)");
    for(std::string line; std::getline(std::cin, line);)
    {
        auto numBegin = 
                std::sregex_iterator(line.begin(), line.end(), num_regex);
        auto numEnd = std::sregex_iterator();

        uint64_t goal = std::stoull((*numBegin).str());
        std::vector<uint64_t> values;
        numBegin++;
        
        for(auto it = numBegin; it != numEnd; it++)
            values.push_back(std::stoull((*it).str()));

        int i = 0;
        int subTotal = values.at(i);
        bool valid = true;

        std::function<bool(uint64_t, int, int)> recurse;
        recurse = [goal, &recurse, &values](uint64_t subTotal, int i, int op)
            {
                if(i >= values.size())
                    return false;

                uint64_t value = values.at(i);
                if(op == 0) // mult
                    subTotal *= value;
                else if(op == 1) // add
                    subTotal += value;
                else if(op == 2) // combine
                    subTotal = std::stoull(std::to_string(subTotal) + std::to_string(value));

                if(subTotal == goal) return true;
                if(subTotal > goal) return false;
                
                return recurse(subTotal, i+1, 0) || recurse(subTotal, i+1, 1) || recurse(subTotal, i+1, 2);
            };

        valid = recurse(subTotal, i+1, 0) || recurse(subTotal, i+1, 1) || recurse(subTotal, i+1, 2);
        
        if(valid) answer += goal;
    }
    std::cout << "answer: " << answer <<  std::endl;

    return 0;
}
