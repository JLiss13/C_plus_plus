#include <iostream>
#include <string>

class Solutions
{
    public:
        std::string countAndSay(int n)
        {
            if (n == 1) 
            {
                return "1";  // Base case
            }

            std::string result = "1";  // Initialize with the first term

            for (int i = 2; i <= n; i++) 
            {
                std::string next = "";
                int count = 1;

                for (int j = 1; j < result.length(); j++) 
                {
                    if (result[j] == result[j - 1]) 
                    {
                        count++;  // Increment count for the same digit
                    } 
                    else 
                    {
                        next += std::to_string(count) + result[j - 1];  // Say the count and the digit
                        count = 1;  // Reset count for the new digit
                    }
                }

                next += std::to_string(count) + result.back();  // Handle the last character
                result = next;  // Update result for the next term
                std::cout<<result<<std::endl;
            }

            return result;
        }
};

int main() {
    int n = 5;
    Solutions* solution = new Solutions();
    std::string result = solution->countAndSay(n);
    std::cout << "Count-and-say sequence for n = " << n << ": " << result << std::endl;
    return 0;
}