/// Code practice assignment
// Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

// Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

// Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
// Return k.

#include <iostream>
// #include "merge_sort_class.h"
#include <memory>
#include <vector>

using namespace std;
class Remove_duplicate_class
{
    public:
        Remove_duplicate_class(std::string& _name)
        {
            this->name = _name;
        }
        
        ~Remove_duplicate_class()
        {
            
        };

        int removeDuplicates(vector<int>& nums)
        {
            // Sort all the duplicates together
            std::sort(nums.begin(), nums.end());

            // Move all the duplicates to the end
            //https://en.cppreference.com/w/cpp/algorithm/unique
            auto last = std::unique(nums.begin(), nums.end());
            
            // Remove all instances of the duplicates
            nums.erase(last, nums.end());

            // output
            int k = nums.size();
            return k;
        }

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
    std::unique_ptr<Remove_duplicate_class> temp_class(new Remove_duplicate_class(name_str));

    // Case study 1
    int arr_1[] = {1,1,2};
    int n_1 = sizeof(arr_1) / sizeof(arr_1[0]); 
    std::vector<int> nums_1(arr_1, arr_1 + n_1);

    int output_1 = temp_class->removeDuplicates(nums_1);
    cout << output_1 << endl;

    // Case study 2
    int arr_2[] = {0,0,1,1,1,2,2,3,3,4};
    int n_2 = sizeof(arr_2) / sizeof(arr_2[0]); 
    std::vector<int> nums_2(arr_2, arr_2 + n_2);

    int output_2 = temp_class->removeDuplicates(nums_2);
    cout << output_2 << endl;

}