#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

void printVector(const vector<int>& v, const string& msg = "")
{
    if (!msg.empty()) cout << msg << endl;
    for (int x : v) { cout << x << " "; }
    cout << endl;}

void printReverse(const vector<int>& v)
{
    for (auto iter = v.rbegin(); iter != v.rend(); ++iter)
    {
        cout << *iter << " "; 
    }
    cout << endl;
}

vector<int> readVector()
{
    cout << "Enter the vector elements seperated by spaces: ";
    string line;
    getline(cin, line);
    stringstream ss(line);
    int x;
    vector<int> v;
    while (ss >> x)
    {
        v.push_back(x);
    }
    return v;
}

void getStats(const vector<int>& v)
{
    if (!v.empty())
    {
        int minNum = v[0], maxNum = v[0];
        int sum = 0;
        for (int i : v)
        {
            minNum = min (minNum, i);
            maxNum = max (maxNum, i);
            sum += i;
        }
        cout << "Vector stats:\n" 
             << "Min value= " << minNum << "\n"
             << "Max value= " << maxNum << "\n"
             << "Sum= " << sum << endl;
    }
}

vector<int> dedupOrdered(const vector<int>& v)
{
    vector<int> dedup_ordered;
    unordered_set<int> seen;
    for (int x : v)
    {
        if(!seen.count(x))
        {
            seen.insert(x);
            dedup_ordered.push_back(x);
        }
    }
    return dedup_ordered;
}

vector<int> dedupSorted(const vector<int>& v)
{
    vector<int> dedup_sorted = v;
    sort(dedup_sorted.begin(), dedup_sorted.end());
    dedup_sorted.erase(unique(dedup_sorted.begin(), dedup_sorted.end()), dedup_sorted.end());
    return dedup_sorted;
}