#include <unordered_set>
#include <vector>
#include <functional>

using namespace std;
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        return hash_val(p.first, p.second);
    }
};

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        vector<int> v;
        unordered_set<pair<int, int>, pair_hash> block;
        for (int i = 0; i < obstacles.size(); i++)
        {
            block.insert(make_pair(obstacles[i][0], obstacles[i][1]));
        }
    }
};