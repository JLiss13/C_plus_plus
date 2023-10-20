/// Code practice assignment

// You are given two integer arrays nums1 and nums2, sorted in increasing order, 
// and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

// Merge nums1 and nums2 into a single array sorted in increasing order.

// The final sorted array should not be returned by the function, but instead be stored 
// inside the array nums1. To accommodate this, nums1 has a length of m + n, 
// where the first m elements denote the elements that should be merged, 
// and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

#include <iostream>
// #include "merge_sort_class.h"
#include <memory>
#include <vector>

using namespace std;
class Merge_sort_class
{
    public:
        Merge_sort_class(std::string& _name)
        {
            this->name = _name;
        }
        
        ~Merge_sort_class()
        {
            
        };

        void merge_function(vector<int>& num1, int m, vector<int>& num2, int n)
        {
            // Remove the last m number of elements
            int vector_size = num1.size();
            for(int i=0; i<vector_size-m; i++)
            {
                num1.pop_back();
            }

            // Merge the vectors
            num1.insert(num1.end(), num2.begin(), num2.end());

            // Sort them in increasing order (Lowest value on the top)
            sort(num1.begin(), num1.end());

            for (int i = 0; i < num1.size(); i++)
            {
                cout << num1[i] << endl;
            }
        };

    private:
        std::string name;
};

using namespace std;
int main()
{
    cout << "Start the merge sorted array tasks" << endl;
    std::string name_str = "class_1";
    std::unique_ptr<Merge_sort_class> temp_class(new Merge_sort_class(name_str));

    // Make the nums1 vector
    int arr_1[] = {1,2,3,0,0,0};
    int n_1 = sizeof(arr_1) / sizeof(arr_1[0]); 
    std::vector<int> nums1(arr_1, arr_1 + n_1);

    // nums_1{}
    int m = 3;

    // Make the nums1 vector
    int arr_2[] = {2,5,6};
    int n_2 = sizeof(arr_2) / sizeof(arr_2[0]); 
    std::vector<int> nums2(arr_2, arr_2 + n_2);

    int n = 3;
    temp_class->merge_function(nums1,m,nums2,n);
}