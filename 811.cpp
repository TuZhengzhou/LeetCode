#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        vector<string> ans;
        unordered_map<string, int> counts;
        for (auto &cpdomain : cpdomains)
        {
            int space = cpdomain.find(' ');
            int count = stoi(cpdomain.substr(0, space));
            string domain = cpdomain.substr(space);
            for (int i = 0; i < domain.size(); i++)
            {
                if (domain[i] == ' ' || domain[i] == '.')
                {
                    string subdomain = domain.substr(i + 1);
                    counts[subdomain] += count;
                }
            }
        }
        for (auto &[subdomain, count] : counts)
        {
            ans.emplace_back(to_string(count) + " " + subdomain);
        }
        return ans;
    }
};