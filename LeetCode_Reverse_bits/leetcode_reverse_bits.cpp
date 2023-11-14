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
        uint32_t reverseBits(uint32_t n) 
        {   
            std::string n_bin_string = bitset<32>(n).to_string();
            std::string reversedString = "";
            // Convert to binary string array
            for (int i=n_bin_string.size()-1;i>=0;i--)
            {
                reversedString+=n_bin_string[i];
            }

            // Convert the binary string back to uint32_t
            bitset<32> bits_output(reversedString);
            uint32_t reversedOutput = static_cast<int>(bits_output.to_ullong());
            return reversedOutput;
        }
        
};
int main(){
    Solution* solution = new Solution();

    uint8_t val_1 = 0b00001111;
    
    cout << "Add binary Input example 1" << endl;
    uint32_t a_1 = 0b00000010100101000001111010011100;
    cout << solution->reverseBits(a_1) << endl;

    cout << "Add binary Input example 2" << endl;
    uint32_t a_2 = 0b11111111111111111111111111111101;
    cout << solution->reverseBits(a_2) << endl;

    return 0;
}