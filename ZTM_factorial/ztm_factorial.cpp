// Make a graph using C++

#include <iostream>
// Write two functions that finds the factorial of any number. One should use recursive, the other should just use a for loop

class Factorial 
{
public:
    int findFactorialRecursive(int number)
    {
        // code here
        if (counter == 0)
        {
            max_iterations = number;
        }
        counter++;
        if (counter < max_iterations)
        {
            // Setup a recursive case
            answer = answer*number;
            number--;
            return findFactorialRecursive(number);
        }
        else
        {
            // Setup a base case (exit plan)
            return answer;
        }
    }

    int findFactorialIterative(int number) 
    {
        int mod_num = number-1;
        int temp_answer=number;
        for (int i=0;i<number-1;i++)
        {
            temp_answer = temp_answer * mod_num;
            mod_num--;
        }
        return temp_answer; 
    }
private:
    int counter;
    int max_iterations;
    int answer{1};
};

int main() 
{
    Factorial* factorial = new Factorial();
    int iterative_answer = factorial->findFactorialIterative(5);
    int recurisve_answer = factorial->findFactorialRecursive(5);
    std::cout << iterative_answer << std::endl;
    std::cout << recurisve_answer << std::endl;

    return 0;
}