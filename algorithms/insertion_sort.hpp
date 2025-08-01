#pragma once
#include "sort_stepper.hpp"

/*
    Short insertion sort algorithm:
    
    for i from 1 to n-1
        key = values[i]
        j = i - 1
        while j >= 0 and values[j] > key
            values[j + 1] = values[j]
            j--
        values[j + 1] = key

*/

class InsertionSortStepper : public SortStepper {
    int i = 1, j = 0, key = 0;
    bool inserting = false;
public:
    bool step(std::vector<int>& values) override {
        int n = values.size();
        if (i < n) {
            if (!inserting) {
                key = values[i];
                j = i - 1;
                inserting = true;
            }
            if (j >= 0 && values[j] > key) {
                values[j + 1] = values[j];
                j--;
                return true;
            } else {
                values[j + 1] = key;
                i++;
                inserting = false;
                return true;
            }
        }
        return false;
    }
    int getCurrentIndex() const override {
        return i;
    }
    int getCurrentComparisonIndex() const override {
        return j;
    }
};    