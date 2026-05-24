#include <iostream>
#include <unordered_map>
#include <vector>
#include "../../include/utils.hpp"

using namespace std;

int main()
{
    unordered_map<char, int> freq;
    std::string s = "ramakrishnahari";
    for (char c : s)
    {
        freq[c]++;
    }
    utils::print_unordered_map(freq);
    
    
    vector <string> v = {"rama", "krishna", "hari"}; 
    unordered_map<string, int> freq1 = utils::createFreqMap(v);
    utils::print_unordered_map(freq1);
    
    vector <int> nums = {1, 2,3,4 ,56, 78,9};
    unordered_map<int, int> freq2 = utils::createFreqMap(v);
    utils::print_unordered_map(freq2);
    
    return 0;
}
