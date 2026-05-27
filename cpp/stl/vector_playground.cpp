#include <iostream>
#include "../../include/utils.hpp"


int main()
{
    vector <int> original = utils::read_vector<int>();

    utils::print_vector(original, "The elements of the vector are: ");
    
    std::cout << "The elements of the vector in reverse order: " << std::endl;
    
    utils::print_reverse(original);

    vector<int> asc = original;
    sort(asc.begin(), asc.end());
    utils::print_vector(asc, "The elements of the ascending ordered vector: ");

    vector<int> desc = original;
    sort(desc.begin(), desc.end(), [](int a, int b){
        return a > b ;
    });
    utils::print_vector(desc, "The elements of the descending ordered vector: ");

    utils::get_stats(original);
    
    // Remove duplicates can be done by two approaches
    // 1. unsorted array duplicate remove
    
    vector<int> dedup_order_preserved = utils::dedup_ordered(original);
    utils::print_vector(dedup_order_preserved, "Uniq elements without sorting: ");

    // 2. sorted array duplicate remove
    vector<int> dedup_sorted = utils::dedup_sorted(original);
    utils::print_vector(dedup_order_preserved, "Uniq elements with sorting: ");

    return 0;

}