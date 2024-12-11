#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>

template <typename T,typename U>                                                   
std::pair<T,U> operator+(const std::pair<T,U> & l,const std::pair<T,U> & r) {   
    return {l.first+r.first,l.second+r.second};                                    
}

int main(int argc, char * argv[])
{
    std::vector<int> first, second;

    int answer = 0;
    std::string grid;
    int gW = 0, gH = 0;
    for(std::string line; std::getline(std::cin, line);)
    {
        grid.append(line);
        gH++;
        gW = line.size();
    }
    std::vector<bool> visited(gW*gH, false );

    int guard_pos = grid.find("^");
    std::pair<int, int> current = { guard_pos / gW, guard_pos % gH };

    std::vector<std::pair<int,int>> directions = { {-1, 0},
                                                   {0, 1},
                                                   {1, 0},
                                                   {0, -1} };
    int dirInd = 0;

    auto inBounds = [&grid, &gW, &gH](std::pair<int, int>&pos)
        {
            return pos.first >= 0 && pos.first < gH
                && pos.second >=0 && pos.second < gW;
        };

/*    visited.at(current.first * gW + current.second) = true;
    std::pair<int, int> nextSpot = current + directions.at(dirInd);
    while(inBounds(nextSpot))
    {
        if(grid.at(nextSpot.first *gW + nextSpot.second) == '#')
            dirInd = (dirInd + 1)%4;

        current = current + directions.at(dirInd);
        visited.at(current.first * gW + current.second) = true;

        nextSpot = current + directions.at(dirInd);
    }
    answer = std::count(visited.begin(), visited.end(),
                        [](bool x){ return x; });
*/
    std::pair<int, int> guard = current;
    
    std::vector<std::pair<int, int>> newGridCreator;    
    
    // Run through grids
        int dirInd = 0;
        current = guard + directions.at(dirInd);
        while()
        

    std::cout << "answer " << answer << std::endl;

    return 0;
}
