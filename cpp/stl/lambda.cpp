#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int x = 10;
	
	// capture by reference
	auto f = [&](){
		x++;
		cout << "x is " << x;
	};

	x = 20;
	cout << "x in main is " << x << endl;
	f();

	cout << endl;

	vector<int> nums = {7, 3, 54,6,5, 1, 2};

	// ascending sort
	sort(nums.begin(),nums.end(),
		[](int a, int b){
			return a < b ;
		});

	cout << "ascending sorted vector : " << endl;
	for (int x : nums)
		cout<< x << " ";

	// descending sort	
	sort(nums.begin(), nums.end(),
		[](int a, int b){
			return a > b ; 
		});
	
	cout << endl;

	cout << "descending sorted vector : " << endl;
	for (int x : nums)
		cout<< x << " ";

	cout << endl;

	vector<pair<int, int>> numPairs = {{1, 1}, {2, 4}, {3, 2}, {4, 3}};
	cout<< "pairs" << endl;
	for (auto p : numPairs)
		cout << p.first << " , " << p.second << endl;
	
	// sort pairs by second	
	sort(numPairs.begin(), numPairs.end(),
		[](const auto& p1, const auto& p2){
			return p2.second > p1.second;
		});

	cout<< "sort pairs by second: " << endl;
	for (auto p : numPairs)
		cout << p.first << " , " << p.second << endl;
}
