#include<string>
class Solution {
public:
    bool squareIsWhite(std::string coordinates) {
        return (coordinates[0]^coordinates[1]) & 0x1;
    }
};