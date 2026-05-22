#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;

void printVector(const vector<int>& v, const string& msg = "")
{
    if (!msg.empty()) cout << msg << endl;
    for (int x : v) cout << x << " ";
    cout << endl;
}

void readVector (vector <int>& original)
{
    original.clear();
    cout << "Enter the integer elements of vector: " << endl;
    string line;
    getline(cin, line);
    int x;
    stringstream ss(line);

    while (ss >> x)
    {
        original.push_back(x);
    }
}

void printMinMaxSum(const vector<int> & original)
{    
    if (!original.empty())
    {
        int maxNum = original[0], minNum = original[0], sum = 0;
        for (int i : original)
        {
            maxNum = max(maxNum, i);
            minNum = min(minNum, i);
            sum += i;
        }
           
        cout << "Max element is: " << maxNum << ", "
             << "Min element is: " << minNum << ", "
             << "Sum of elements is: " << sum << endl;
    }
}

int main()
{
    vector <int> original;
    readVector(original);

    printVector(original, "The elements of the vector are: ");

    cout << "The elements of the vector in reverse order: " << endl;
    for (auto iter = original.rbegin(); iter != original.rend(); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;

    vector<int> asc = original;
    sort(asc.begin(), asc.end());
    printVector(asc, "The elements of the ascending ordered vector: ");

    vector<int> desc = original;
    sort(desc.begin(), desc.end(), [](int a, int b){
        return a > b ;
    });
    printVector(desc, "The elements of the descending ordered vector: ");

    printMinMaxSum(original);


    // Remove duplicates can be done by two approaches
    // 1. unsorted array duplicate remove
    vector<int> dedup_order_preserved;
    unordered_set<int> seen;
    for (const auto& i: original)
    {
        if(!seen.count(i))
        {
            seen.insert(i);
            dedup_order_preserved.push_back(i);
        }
    }
    printVector(dedup_order_preserved, "Uniq elements without sorting: ");


    // 2. sorted array duplicate remove
    vector<int> dedup_sorted = asc;
    /*
    auto iter = unique(dedup_sorted.begin(), dedup_sorted.end());
    dedup_sorted.erase(iter,dedup_sorted.end());
    */
    dedup_sorted.erase (unique (dedup_sorted.begin(), dedup_sorted.end()), dedup_sorted.end());
    printVector(dedup_sorted, "Uniq elements with sorting: ");

    return 0;

}