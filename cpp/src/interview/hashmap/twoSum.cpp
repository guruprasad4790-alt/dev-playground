#include "../../../include/utils.hpp"

using namespace std;

int main()
{
    vector<int> v = utils::read_vector<int>();
    cout << "Enter the two sum expected: ";
    int twoSum;
    cin >> twoSum;
    //unordered_map<int,int> complementMap;
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
    return 0;
}