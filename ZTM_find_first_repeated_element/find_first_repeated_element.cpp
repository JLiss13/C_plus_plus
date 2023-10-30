// Find the first repeated value in the array using hash table in C++ aka std::unordered_map()
//
// Inputs: 
//    Given an array = [2,5,1,2,3,5,1,2,4];
//    Given an array = [2,1,1,2,3,5,1,2,4];
//    Given an array = [2,3,4,5];
// Output:
// 2
// 1
// undefined
// Goal:
//      Avoid brute/naive approach each time
//      Space complexity O(n) and Time complexity O(a+b+c) for all hash_table operations
#include <iostream>
#include <unordered_map>
#include <typeinfo>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
class Hash_table
{
    public:
        Hash_table(std::string name)
        {
            list_name = name;
        }

        template <class key_type, class value_type>
        void Set(const key_type& key, const value_type& value)
        {
            if (typeid(key) == typeid(int))
            {
                int key_temp = key;
                if (typeid(value) == typeid(int))
                {
                    int value_temp = value;
                    myTable[key] = value_temp;
                }
                else
                {
                    cout<<"Value must be a integer and/or key string must be a non-empty int"<<endl;
                }
            }
            else
            {
                cout<<"Key must be a int"<<endl;
            }
        }

        template <class key_type>
        double Get(const key_type key)
        {
            if (typeid(key) == typeid(int))
            {
                return myTable[key];
            }
            else
            {
                cout << "Key should be a string" << endl;
            }

            return -999; //If -999 occurs than the Get function do not retrieve any values. Error occurred.
        }

        template <class T>
        void PrintUnorderedMap(const T& myMap)
        {
            // Print all elements in the unordered_map
            for (const auto& pair : myMap) {
                std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
            }
        }

        // Add keys function that prints out an array of keys
        std::vector<int> Keys()
        {
            std::vector<int> key_list;
            for (const auto& pair : myTable) {
                std::cout << pair.first << std::endl;
                key_list.push_back(pair.first);
            }
            return key_list;
        }
        void ClearMapTable()
        {
            myTable.clear();
        }

        int FindFirstRepeatedElement(const std::vector<int> input_array)
        {
            // Find the max value in order to create the hash table
            auto minElement = std::min_element(input_array.begin(), input_array.end());
            auto maxElement = std::max_element(input_array.begin(), input_array.end());

            int max_element = *maxElement;
            int min_element = *minElement;
            
            // Create the hash table and initialize all values to 0
            for (int i=min_element; i<max_element+1; i++)
            {
                Set(i,0);
            }

            PrintUnorderedMap(myTable);
            
            // Find the first repeated element, return when the first value > 2
            for (int j=0; j <  input_array.size(); j ++)
            {
                // Walk thorugh the hash table
                auto it = myTable.find(input_array[j]);
                if (it != myTable.end())
                {
                    myTable[input_array[j]]++;
                    std::cout << "Key exists: " << it->first << std::endl;

                    // Check if the value in the hash_table > 1 than that value is the first repeated element

                    if (it->second > 1)
                    {
                        std::cout << "Found the first repeated element: " << std::endl << it->first << std::endl;
                        return it->first;
                    }
                }
                else
                {
                    std::cout << "Key does not exist." << std::endl;
                }
            }

            return 9999;
        }
    private:
        std::unordered_map<int , int> myTable;
        std::string list_name;
};

int main()
{
    //Instantiate the class
    Hash_table check_table("Check recursion Hash Table");
    
    // Setting examples
    cout << "Case 1 First Repeated Element Check" << endl;
    check_table.ClearMapTable();
    std::vector<int> array_1 = {2,5,1,2,3,5,1,2,4};
    check_table.FindFirstRepeatedElement(array_1);
    
    cout << "Case 2 First Repeated Element Check" << endl;
    check_table.ClearMapTable();
    std::vector<int> array_2 = {2,1,1,2,3,5,1,2,4};
    check_table.FindFirstRepeatedElement(array_2);

    cout << "Case 3 First Repeated Element Check" << endl;
    check_table.ClearMapTable();
    std::vector<int> array_3 = {2,3,4,5};
    check_table.FindFirstRepeatedElement(array_3);
    return 0;

}