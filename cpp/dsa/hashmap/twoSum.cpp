#include "../../../include/utils.hpp"

using namespace std;

void logTwoSum(const vector<int>& v, int twoSum)
{
    unordered_set<int> seen;

    for (int x : v)
    {
        int needed = twoSum-x;
        if (seen.count(needed))
        {
            cout<< "Found " << x << " and " << twoSum-x << " which add up to " << twoSum << endl;
        }
        seen.insert(x);
    }
    return;
}


vector<pair<int,int>> evalTwoSum(const vector<int>& v, int twoSum)
{
    vector<pair<int,int>> indexPairs;
    unordered_map<int, int> seen;
    int i=0;
    for (int x : v)
    {
        int needed = twoSum-x;
        if (seen.count(needed))
        {
            indexPairs.push_back(make_pair(i, seen[needed]));
        }
        seen[x] = i;
        i++;
    }
    return indexPairs;
}

int main()
{
    vector<int> v = utils::read_vector<int>();
    cout << "Enter the two sum expected: ";
    int twoSum;
    cin >> twoSum;
    //unordered_map<int,int> complementMap;
    logTwoSum(v, twoSum);
    vector<pair<int,int>> pv = evalTwoSum(v,twoSum);
    if(pv.empty()) return 0;
    for (auto p : pv)
    {
        cout << "[" << p.first << ", " << p.second << "]" << endl;

    }
    
    return 0;
}