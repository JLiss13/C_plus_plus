// You are given two integer arrays nums1 and nums2, sorted in increasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in increasing order.

// The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
#include <iostream>
#include <vector>
#include "merge_sort_class.h"

using namespace std;

Merge_sort_class::Merge_sort_class(std::string& _name);
{
    this->name=_name;
}

// Merge_sort_class::~Merge_sort_class()
// {
//     std::cout<<"Inside the destructor"<<std::endl;
// }

void Merge_sort_class::merge(vector<int>& num1, int m, vector<int>& num2, int n)
{

}