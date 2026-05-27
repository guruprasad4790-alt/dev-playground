#include <iostream>
#include <unordered_set>
#include <vector>
#include "../../../include/utils.hpp"

using namespace std;

bool containsDuplicate(const vector<int>& v)
{
    unordered_set<int> seenSet;
    if (v.empty()) return false;

    for (int x : v)
    {
        if (seenSet.count(x))
            return true;
            
        seenSet.insert(x);            
    }
    return false;
}

int main()
{
    vector<int> v = utils::read_vector<int>();
    cout << "containsDuplicate: " << (containsDuplicate(v) ? "yes" : "no");
    return 0;
}