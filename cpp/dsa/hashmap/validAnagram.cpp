#include "../../../include/utils.hpp"

using namespace std;

unordered_map<char, int> createFreqMap(const string& s)
{
    unordered_map<char, int> freq;
    for (char c : s)
    {
        freq[c]++;
    }
    return freq;
}

bool validAnagram(const string& s1, const string& s2)
{
    if(s1.length() != s2.length())
        return false;

    unordered_map<char, int> freq1 = createFreqMap(s1);
    for (char c : s2)
    {
        freq1[c]--;
        if (freq1[c] < 0)
            return false;
    }
    for (char c : s1)
        if (freq1[c] != 0)
            return false;
    return true;
    
    /*
    unordered_map<char, int> freq2 = createFreqMap(s2);

    for (const auto& p : freq1)
    {
        if (freq2[p.first] != p.second)
            return false;
    }
    */
    return true;
}


int main()
{
    string s1, s2;
    cout << "Enter the first string: " << endl;
    cin >> s1;
    cout << "Enter the second string: "<< endl;
    cin >> s2;
    cout << (validAnagram(s1,s2)? "Yes, " : " No, Not ") << "valid anagram";
}