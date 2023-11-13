// Compiled with: g++ -Wall -std=c++14 -pthread

#include <iostream>
#include <bitset>
// Objective:
// Conversion function
// Input: two ints (32 bit int)
// Output: 64 bit int

// For fun make a function that does the reverse
using namespace std;
std::vector<uint32_t> Convert64IntTo32Int(uint64_t full)
{
    // Grab least 32 bits and those will be the low 32 bit
    // Bit shift all the values from the full packet back 32 bits then static cast that as uint32_t
    //  Create variable of 2^32 
    uint64_t operator_32 = 0xFFFFFFFFULL; // 32-bit unsigned long long with 1st 32 lsbs all 1  
    // cout << std::bitset<8 * sizeof(int)>(operator_32).to_string()<< endl;
    uint64_t low64 = (operator_32 & full); // Take only the ls 32 bits
    uint32_t low = static_cast<uint32_t>(low64); //Cast to 32 bit value

    // Grab the full bit value shift the values back to 32 bits and then static_cast
    uint32_t high = static_cast<int32_t>(full >> 32);
    std::vector<uint32_t> two_ints = {low, high};
    return two_ints;
}

uint64_t Convert32IntTo64bit(uint32_t low, uint32_t high)
{
    // Shifts the bits 32  positions using << and then performs a bitwise OR operation with the low value
    return (static_cast<uint64_t>(high) << 32) | low;
}

using namespace std;

int main(){
    cout << "convert two 32 bit uint to one 64 bit uint" << endl;
    uint32_t uinput_1 = 12;
    uint32_t uinput_2 = 4;
    uint64_t uint_64_output = Convert32IntTo64bit(uinput_1, uinput_2);
    cout << uint_64_output << endl;

    cout << "convert 64 bit uint to two 32 bit uint" << endl;
    std::vector <uint32_t> original_int_inputs = Convert64IntTo32Int(uint_64_output);
    for (auto& value : original_int_inputs)
    {
        cout << value << endl;
    }
    return 0;
}