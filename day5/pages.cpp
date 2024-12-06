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

    int answer = 0, answer2 = 0;
    std::map<int, std::set<int>> page_rules;
    std::regex rules("(\\d+)\\|(\\d+)");
    for(std::string line; std::getline(std::cin, line);)
    {
        if(line.empty())
            break;

        std::smatch num;
        std::regex_match(line, num, rules); 
        page_rules[std::stoi(num[1])].insert(std::stoi(num[2]));
    }

    for(std::string line; std::getline(std::cin, line);)
    {
        std::istringstream iss(line);
        std::string num;
        std::vector<int> pages;
        while(std::getline(iss, num, ','))
        {
            pages.push_back(std::stoi(num));
        }
        
        bool in_order = true;
        for(int i = 0; i < pages.size(); i++)
        {
            if(!page_rules.contains(pages.at(i)))
                continue;

            for(int j = 0; j < i; j++)
            {
                if(!page_rules[pages.at(j)].contains(pages.at(i)))
                {
                    in_order = false;
                    break;
                }
            }

            for(int j = i+1; j < pages.size(); j++)
            {
                if(!page_rules[pages.at(i)].contains(pages.at(j)))
                {
                    in_order = false;
                    break;
                }
            }
        }
        if(in_order)
        {
            int mid = floor(pages.size() / 2);
            answer += pages.at(mid);
        }
    }
    std::cout << "answer: " << answer << std::endl;
    

    return 0;
}
