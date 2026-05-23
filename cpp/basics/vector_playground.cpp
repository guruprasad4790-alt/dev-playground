#include <iostream>
#include "vector_utils.hpp"


int main()
{
    vector <int> original = vecutils::read_vector<int>();

    vecutils::print_vector(original, "The elements of the vector are: ");
    
    std::cout << "The elements of the vector in reverse order: " << std::endl;
    
    vecutils::print_reverse(original);

    vector<int> asc = original;
    sort(asc.begin(), asc.end());
    vecutils::print_vector(asc, "The elements of the ascending ordered vector: ");

    vector<int> desc = original;
    sort(desc.begin(), desc.end(), [](int a, int b){
        return a > b ;
    });
    vecutils::print_vector(desc, "The elements of the descending ordered vector: ");

    vecutils::get_stats(original);
    
    // Remove duplicates can be done by two approaches
    // 1. unsorted array duplicate remove
    
    vector<int> dedup_order_preserved = vecutils::dedup_ordered(original);
    vecutils::print_vector(dedup_order_preserved, "Uniq elements without sorting: ");

    // 2. sorted array duplicate remove
    vector<int> dedup_sorted = vecutils::dedup_sorted(original);
    vecutils::print_vector(dedup_order_preserved, "Uniq elements with sorting: ");

    return 0;

}