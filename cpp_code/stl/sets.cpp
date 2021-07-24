#include <set>
#include <unordered_set>
#include <unordered_map>
#include <functional>

using namespace std;

template <typename T>
inline void hash_combine(std::size_t &seed, const T &val)
{
    seed ^= std::hash<T>()(val) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

template <typename T>
inline void hash_val(std::size_t &seed, const T &val)
{
    hash_combine(seed, val);
}

template <typename T, typename... Types>
inline void hash_val(std::size_t &seed, const T &val, const Types &...args)
{
    hash_combine(seed, val);
    hash_val(seed, args...);
}

template <typename... Types>
inline std::size_t hash_val(const Types &...args)
{
    std::size_t seed = 0;
    hash_val(seed, args...);
    return seed;
}
struct pair_hash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        return hash_val(p.first, p.second);
    }
};

int main()
{
    unordered_set<pair<int, int>, pair_hash> slopeCount;
    unordered_map<pair<int, int>, long, pair_hash> seen;
    slopeCount.insert(make_pair(1, 2));
    return 0;
}