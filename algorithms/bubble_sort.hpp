#pragma once
#include "sort_stepper.hpp"

/*

    Actual short bubble sort : 

    for i from 0 to n-1
        for j from 0 to n-i-2
            if values[j] > values[j+1]
                swap(values[j], values[j+1])    
*/

class BubbleSortStepper : public SortStepper {
    int i = 0, j = 0;
public:
    bool step(std::vector<int>& values) override {
        int n = values.size();
        if (i < n - 1) {
            if (j < n - i - 1) {
                if (values[j] > values[j + 1])
                    std::swap(values[j], values[j + 1]);
                j++;
            } else {
                j = 0;
                i++;
            }
            return true;
        }
        return false;
    }
    int getCurrentIndex() const override {
        return j; // Return the index of the current element being processed
    }
    int getCurrentComparisonIndex() const override {
        return j+1;// Return the index of the current comparison element
    }
};