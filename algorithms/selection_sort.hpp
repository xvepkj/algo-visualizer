#pragma once
#include "sort_stepper.hpp"
/*
    Short selection sort algorithm:

    for i from 0 to n-1
        minIndex = i
        for j from i+1 to n-1
            if values[j] < values[minIndex]
                minIndex = j
        swap(values[i], values[minIndex])

*/
class SelectionSortStepper : public SortStepper {
    int i = 0, j = 0;
public:
    bool step(std::vector<int>& values) override {
        int n = values.size();
        if (i < n - 1) {
            if (j < n) {
                int minIndex = i;
                if(values[j] < values[minIndex]) {
                    minIndex = j;
                }
                std::swap(values[i], values[minIndex]);
                j++;
            } else {
                i++;
                j = i + 1;
            }
            return true;
        }
        return false;
    }
    int getCurrentIndex() const override {
        return i; // Return the index of the current element being processed
    }
    int getCurrentComparisonIndex() const override {
        return j; // Return the index of the current comparison element
    }
};