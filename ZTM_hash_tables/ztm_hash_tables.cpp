// Make a hash table using a C++ std::unordered_map()
// Inputs: 
//    Take in the following inputs  "grapes", which equals $1 and "apples", which equals $0.5, "", which equals 100, and "stuff", which equals "asdf". Check of the errors and return error messages if the data does not meet the criteria

// Output the hashtable if the inputs are correct
// Space complexity O(n) and Time complexity O(1) for all hash_table operations
#include <iostream>
#include <unordered_map>
#include <typeinfo>
#include <string>

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
            if (typeid(key) == typeid(std::string) && key.size() > 1)
            {
                std::string key_temp = key;
                if (typeid(value) == typeid(double))
                {
                    double value_temp = value;
                    myShoppingList[key] = value_temp;
                    PrintUnorderedMap(myShoppingList);
                }
                else
                {
                    cout<<"Value must be a integer and/or key string must be a non-empty string"<<endl;
                }
            }
            else
            {
                cout<<"Key must be a string"<<endl;
            }

        }

        template <class key_type>
        double Get(const key_type key)
        {
            if (typeid(key) == typeid(std::string))
            {
                std::string key_temp = key;
                if (key_temp.size() > 1)
                {
                    return myShoppingList[key];
                }
                else
                {
                    cout << "Size of the key should be larger than 1" << endl;
                }
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
    private:
        std::unordered_map<std::string , double> myShoppingList;
        std::string list_name;
};

int main()
{
    //Instantiate the class
    Hash_table shopping_list("Shopping List");
    
    // Setting examples
    cout << "Case 1 Hash Table example" << endl;
    std::string key_1 = "grapes";
    double value_1 = 1;
    shopping_list.Set(key_1,value_1);

    cout << "Case 2 Hash Table example" << endl;
    std::string key_2 = "apples";
    double value_2 = 2;
    shopping_list.Set(key_2,value_2);

    cout << "Case 3 Hash Table example" << endl;
    std::string key_3 = "";
    double value_3 = 100;
    shopping_list.Set(key_3,value_3);

    // cout << "Case 4 Hash Table example" << endl;
    // std::string key_4 = "key name";
    // std::string value_4 = "unvalid value input";
    // shopping_list.Set(key_4,value_4);

    // Getting examples
    cout << "Case 1 Hash Table Get example" << endl;
    std::string key_5 = "grapes";
    cout << shopping_list.Get(key_5) << endl;
    return 0;
}