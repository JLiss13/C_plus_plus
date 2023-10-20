#ifndef MERGE_SORT_CLASS_H
#define MERGE_SORT_CLASS_H

#include <iostream>
#include <vector>
using namespace std;

class Merge_sort_class
{
    public:
        Merge_sort_class(std::string& name);
        // ~Merge_sort_class();
        void Merge(vector<int>& num1, int m, vector<int>& num2, int n);

    private:
        std::string name;
};

#endif