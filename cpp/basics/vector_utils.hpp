#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <limits>

using namespace std;

template <typename T>
void printVector(const vector<T>& v, const string& msg = "")
{
    if (!msg.empty()) cout << msg << endl;
    for (const T& x : v) { cout << x << " "; }
    cout << endl;
}

template <typename T>
void printReverse(const vector<T>& v)
{
    for (auto iter = v.rbegin(); iter != v.rend(); ++iter)
    {
        cout << *iter << " "; 
    }
    cout << endl;
}

template <typename T>
vector<T> readVector()
{
    cout << "Enter the vector elements seperated by spaces: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string line;
    getline(cin, line);
    stringstream ss(line);

    T x;
    vector<T> v;
    
    while (ss >> x)
        v.push_back(x);
    
    return v;
}

// treating this as numeric only for now
template <typename T>
void getStats(const vector<T>& v)
{
    if (v.empty()) return;

    T minNum = v[0];
    T maxNum = v[0];
    T sum = T();   // default 0

    for (const T& x : v)
    {
        minNum = min(minNum, x);
        maxNum = max(maxNum, x);
        sum += x;
    }

    cout << "Vector stats:\n"
         << "Min = " << minNum << "\n"
         << "Max = " << maxNum << "\n"
         << "Sum = " << sum << endl;
}

template <typename T>
vector<T> dedupOrdered(const vector<T>& v)
{
    vector<T> dedup_ordered;
    unordered_set<T> seen;
    for (const T& x : v)
    {
        if(!seen.count(x))
        {
            seen.insert(x);
            dedup_ordered.push_back(x);
        }
    }
    return dedup_ordered;
}

template <typename T>
vector<T> dedupSorted(const vector<T>& v)
{
    vector<T> dedup_sorted = v;
    sort(dedup_sorted.begin(), dedup_sorted.end());
    dedup_sorted.erase(unique(dedup_sorted.begin(), dedup_sorted.end()), dedup_sorted.end());
    return dedup_sorted;
}