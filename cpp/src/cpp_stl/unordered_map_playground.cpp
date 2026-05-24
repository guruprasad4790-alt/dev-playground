#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

template <typename X, typename Y>
void print_unordered_map (const unordered_map<X,Y>& u_map)
{
    for (const auto& p : u_map)
    {
        cout << "{" << p.first << ", " << p.second << "}" << endl;
    }
}
template <typename T>
unordered_map<T,int> createFreqMap(const vector<T>& vec)
{
    unordered_map<T, int> freqMap;
    for (const T& x : vec)
    {
        freqMap[x]++;
    }
    return freqMap;
}

int main()
{
    unordered_map<char, int> freq;
    std::string s = "ramakrishnahari";
    for (char c : s)
    {
        freq[c]++;
    }
    print_unordered_map(freq);
    
    
    vector <string> v = {"rama", "krishna", "hari"}; 
    unordered_map<string, int> freq1 = createFreqMap(v);
    print_unordered_map(freq1);
    
    vector <int> nums = {1, 2,3,4 ,56, 78,9};
    unordered_map<string, int> freq2 = createFreqMap(v);
    print_unordered_map(freq2);
    
    return 0;
}
