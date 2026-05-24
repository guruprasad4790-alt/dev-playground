#pragma once
#include <vector>
#include <iostream>
#include <sstream>
#include <unordered_set>
#include <algorithm>
#include <string>
#include <limits>
#include <unordered_map>

using namespace std;

namespace utils
{
    template <typename T>
    void print_vector(const vector<T>& v, const string& msg = "")
    {
        if (!msg.empty()) cout << msg << endl;
        for (const T& x : v) { cout << x << " "; }
        cout << endl;
    }

    template<typename T>
    vector<T> input_vector(int n)
    {
        vector<T> v;
        v.reserve (n);
        for (int i=0; i< n; i++)
        {
            T x;
            cin >> x;
            v.push_back(x);
        }
        return v;
    }

    template<typename T>
    T vector_sum(const vector<T>& v)
    {
        T sum = T();
        for (const auto& x : v) { sum+=x; }
        return sum;
    }

    template<typename T>
    T vector_min(const vector<T>& v)
    {
        T x;
        if (v.empty()) return x;
        T minVal = v[0];
        for (const auto& x : v) { minVal = min (minVal, x); }
        return minVal;
    }

    template<typename T>
    T vector_max(const vector<T>& v)
    {
        T x;
        if (v.empty()) return T();
        T maxVal = v[0];
        for (const auto& x : v) { maxVal = max (maxVal, x); }
        return maxVal;
    }


    template <typename T>
    void print_reverse(const vector<T>& v)
    {
        for (auto iter = v.rbegin(); iter != v.rend(); ++iter)
        {
            cout << *iter << " "; 
        }
        cout << endl;
    }

    template <typename T>
    vector<T> read_vector()
    {
        cout << "Enter the vector elements seperated by spaces: ";
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
    void get_stats(const vector<T>& v)
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
    vector<T> dedup_ordered(const vector<T>& v)
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
    vector<T> dedup_sorted(const vector<T>& v)
    {
        vector<T> dedup_sorted = v;
        sort(dedup_sorted.begin(), dedup_sorted.end());
        dedup_sorted.erase(unique(dedup_sorted.begin(), dedup_sorted.end()), dedup_sorted.end());
        return dedup_sorted;
    }

    // unordered_map utils

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
}