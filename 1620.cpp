#include <vector>
using namespace std;

// https://leetcode.cn/problems/coordinate-with-maximum-network-quality/comments/

class Solution
{
public:
    vector<int> bestCoordinate(vector<vector<int>> &towers, int radius)
    {
        vector<int> rec = vector<int>(3, 0);
        vector<vector<int>> powers(51 + radius, vector<int>(51 + radius, 0));
        // rec[0] = 0; // 记录信号强度

        int x, y, min_x, min_y, idx_x, idx_y;
        int power;
        double distant;
        for (auto tower : towers)
        {
            x = tower[0];
            y = tower[1];
            min_x = x - radius;
            min_y = y - radius;
            // cout << "tower: " << x << ", " << y << ", " << tower[2] << endl;
            // cout << "\tmin_x = " << min_x << ", min_y = " << min_y << endl;
            for (idx_x = min_x; idx_x <= x + radius; idx_x++)
            {
                if (idx_x < 0)
                    continue;
                for (idx_y = min_y; idx_y <= y + radius; idx_y++)
                {
                    if (idx_y < 0)
                        continue;
                    distant = sqrt(pow((x - idx_x), 2) + pow((y - idx_y), 2));
                    power = floor(tower[2] / (1 + distant));
                    if (distant <= radius)
                    {
                        powers[idx_x][idx_y] += power;
                        // cout << "\t\tidx_x = " << idx_x << ", idx_y = " << idx_y << ", power = " << powers[idx_x][idx_y] << endl;
                        if (powers[idx_x][idx_y] >= rec[0])
                            if (powers[idx_x][idx_y] > rec[0] || idx_x < rec[1] || (idx_x == rec[1] && idx_y < rec[2]))
                                rec = {powers[idx_x][idx_y], idx_x, idx_y};
                    }
                }
            }
        }
        return {rec[1], rec[2]};
    }
};