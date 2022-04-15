#include "../Helpers.hpp"

// You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.

// Example 1:
// Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
// Output: true

// Example 2:
// Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
// Output: false

class Solution
{
public:
    bool checkStraightLine(const std::vector<std::vector<int>>& coordinates)
    {
        if(coordinates.size() == 2)
            return true;
        
        const int x0 = coordinates[0][0] , x1 = coordinates[1][0];
        const int y0 = coordinates[0][1] , y1 = coordinates[1][1];
        
        const int dx = x1 - x0;
        const int dy = y1 - y0;
        
        for (size_t i = 2u; i < coordinates.size(); ++i) {
            const int x = coordinates[i][0] , y = coordinates[i][1];
            if (dy * (x - x0) != dx * (y - y0)) {
                return false;
            }
        }

        return true;
    }
};

int main(int argc, char** argv)
{
    return EXIT_SUCCESS;
}
