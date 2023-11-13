// Compiled with: g++ -Wall -std=c++14 -pthread

#include <iostream>
#include <bitset>
// Objective:
// Conversion function
// Input: two binary strings
// Output: sum as binary string

// For fun make a function that does the reverse
using namespace std;

class Solution 
{
    public:
        string addBinary(string a, string b)
        {
            // Convert from string to binary or decimal
            std::bitset<64> bits_a(a);
            int a_int = static_cast<int>(bits_a.to_ulong());
            cout << a_int <<endl;

            std::bitset<64> bits_b(b);
            int b_int = static_cast<int>(bits_b.to_ulong());
            cout << b_int <<endl;
            int c_int = a_int + b_int; 
            cout << c_int <<endl;
            
            // Then convert that value back to binary string
            return std::bitset<64>(c_int).to_string();
        }
};
int main(){
    Solution* solution = new Solution();

    cout << "Add binary Input example 1" << endl;
    std::string a_1 = "11";
    std::string b_1 = "1";
    cout << solution->addBinary(a_1,b_1) << endl;

    cout << "Add binary Input example 2" << endl;
    std::string a_2 = "1011";
    std::string b_2 = "1010";
    cout << solution->addBinary(a_2,b_2) << endl;

    return 0;
}