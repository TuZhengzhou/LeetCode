#include <string>
using namespace std;
class Solution
{
public:
    string reformatNumber(string number)
    {
        string ac;
        for (auto c : number)
        {
            if (isdigit(c))
            {
                ac += c;
            }
        }
        string res;
        int n = ac.size();
        // int i;
        // cout << n << endl;
        // if( n % 3 == 1 ){
        //     for( i = 0; i < n-4; i+=3 ){
        //         res += ac.substr(i, 3) + "-";
        //     }
        //     res += ac.substr(i, 2) + "-";
        //     res += ac.substr(i+2);

        // }else{
        //     for( i = 0; i < n-3; i+=3 ){
        //         res += ac.substr(i, 3) + "-";
        //     }
        //     res += ac.substr(i);
        // }
        int pt = 0;
        while (n)
        {
            if (n > 4)
            {
                res += ac.substr(pt, 3) + "-";
                pt += 3;
                n -= 3;
            }
            else
            {
                if (n == 4)
                {
                    res += ac.substr(pt, 2) + "-" + ac.substr(pt + 2, 2);
                }
                else
                {
                    res += ac.substr(pt, n);
                }
                break;
            }
        }
        return res;
    }
};