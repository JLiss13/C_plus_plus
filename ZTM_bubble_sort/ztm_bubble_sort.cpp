#include <iostream>
#include <map>

class Sort 
{
public:
    void BubbleSort(int numbers[])
    { 
        // Sort the array set check every pair and bubbling up the highest one to the end and lowest one to the beginning
        sorted = false;
        int arraySize = sizeof(numbers);
        
        // Create the sort tracker hash table
        for (int i=0;i<sizeof(numbers);i++)
        {
            sort_tracker[numbers[i]]== false;
        }

        while(sorted)
        {
            if(numbers[sort_counter]>numbers[sort_counter+1] &&
                sort_tracker[numbers[sort_counter]] == false)
            {
                int temp_prev = numbers[sort_counter];
                numbers[sort_counter] = numbers[sort_counter+1];
                numbers[sort_counter+1] = numbers[sort_counter];
                sort_counter++;
            }
            else
            {
                // Then the number has a value that is higher than it
                // Stop sorting
                sort_tracker[numbers[sort_counter]] = true;
                sorted_values++;
                sort_counter=0;

                // Exit the while loop when all the hash_table entries are true
                if (sorted_values == sizeof(numbers))
                {
                    sorted=true;
                    break;
                }
            }
        }
    }
private:
    bool sorted;
    int correct_comparsions;
    int sorted_values;
    int yet_to_be_sorted_values;
    int sort_counter;
    std::unordered_map<int,bool> sort_tracker;
};

int main() 
{
    Sort* sort = new Sort();
    int numbers[] = {99, 44, 6, 2, 1, 5, 63, 87, 283, 4, 0};
    sort->BubbleSort(numbers);
}