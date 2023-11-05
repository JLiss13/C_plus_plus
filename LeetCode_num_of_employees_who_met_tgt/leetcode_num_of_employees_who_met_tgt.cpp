// Assumptions:
// Number of employes [0 n-1]
// Each employee i has worked for hours[i]
// Each employee must work at least "target" hrs
// Inputs:
// Given array of non-neg int "hours" of length n and array of int non-neg "target" 
// Output:
// int of the num of employees who worked at least hours >= target

#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solutions
{
    public:
     int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) 
    {
        int numThatMetTgt = 0;
        for (int i=0;i<hours.size();i++)
        {
            if(hours[i]>=target)
            {
                numThatMetTgt++;
            }
        }
        return numThatMetTgt;
    }
        
};

int main() 
{
    Solutions* solution = new Solutions();
    int arr_1[] = {0,1,2,3,4};
    int n_1 = sizeof(arr_1) / sizeof(arr_1[0]); 
    std::vector<int> nums1(arr_1, arr_1 + n_1);
    cout<<solution->numberOfEmployeesWhoMetTarget(nums1,2)<<endl;

    int arr_2[] = {5,1,4,2,2};
    int n_2= sizeof(arr_2) / sizeof(arr_2[0]); 
    std::vector<int> nums2(arr_2, arr_2 + n_2);
    cout<<solution->numberOfEmployeesWhoMetTarget(nums2,6)<<endl;
}