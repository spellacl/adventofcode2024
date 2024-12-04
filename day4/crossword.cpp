#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <numeric>
#include <map>

int main(int argc, char * argv[])
{
    std::vector<int> first, second;

    int answer = 0, answer2 = 0;
    int gW = 0;
    int gH = 0;
    std::string grid;
    for(std::string line; std::getline(std::cin, line);)
    {
        grid.append(line);
        gH++;
        gW = line.size();
    }

    std::function<bool(int, int, int, int, int)> search;
    search = [grid, gW, gH, &search](int i, int j, int incX, int incY, int depth)
        {
            std::map<int, char> check = { {2,'M'}, {1,'A'}, {0,'S'} }; 
            if(depth == -1)
                return true; // only here if depth zero was 'S'
            else if( i < 0 || i >= gW || j < 0 || j >= gH) // value to check if out of bounds
                return false;
            else if(check[depth] == grid.at(i * gW + j))
                return search(i + incX, j + incY, incX, incY, depth - 1);
            else
                return false;
        };

    std::function<bool(int, int)> xmas;
    xmas = [grid, gW, gH](int i, int j)
        {
            // NW   NE    S S  M M  S M  M S
            //    A        A    A    A    A
            // SW   SE    M M  S S  S M  M S

            if( (i+1) >= gW || (i-1) < 0 || (j-1) < 0 || (j+1) >= gH)
                return false;

            std::string diag;
            diag.append(1, grid.at( (i-1)*gW + (j-1) ));
            diag.append(1, grid.at( (i+1)*gW + (j-1) ));
            diag.append(1, grid.at( (i+1)*gW + (j+1) ));
            diag.append(1, grid.at( (i-1)*gW + (j+1) ));
            if( diag == "SSMM" || diag == "MMSS" || diag == "SMMS" || diag == "MSSM")
                return true;
            else
                return false;
        };

    std::vector<std::pair<int, int>> directions = { {-1,  0}, // North
                                                    {-1,  1}, // North East
                                                    {-1, -1}, // North West
                                                    { 1,  0}, // South
                                                    { 1,  1}, // South East
                                                    { 1, -1}, // South West
                                                    { 0, -1}, // West
                                                    { 0,  1}}; // East
    for(int i = 0; i < gW; i++)
    {
        for(int j = 0; j < gH; j++)
        {
            if(grid.at(i * gW + j) == 'X')
            {
                for (const auto& [incX, incY] : directions)
                {
                    answer += search(i + incX, j + incY, incX, incY, 2);
                }
            }
            if(grid.at(i * gW + j) == 'A')
            {
                answer2 += xmas(i,j);
            }
        }
    }
    std::cout << answer << std::endl;
    std::cout << answer2 << std::endl;
    return 0;
}
