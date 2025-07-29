#pragma once
#include <sort_stepper.hpp>

class InsertionSortStepper : public SortStepper {
    int i = 0, j = -1, key = 0;
public:
    bool step(std::vector<int>& values) override {
        int n = values.size();
        if (i < n) {
            if (j >= 0){
                if (values[j] > key) {
                    values[j + 1] = values[j]; 
                }
                j--;
            } else {
                i++;
                key = values[i];
                j = i - 1;
            }
            return true;
        }
        return false;       
    }
}    