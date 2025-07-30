#pragma once
#include <vector>

class SortStepper {
public:
    virtual ~SortStepper() = default;
    virtual bool step(std::vector<int>& values) = 0; // returns false when done
    virtual int getCurrentIndex() const = 0; // returns the index of the current element being processed
    virtual int getCurrentComparisonIndex() const { return -1; } // optional, can be overridden if needed
    virtual int getLeft() const { return -1; }
    virtual int getMid() const { return -1; }
    virtual int getRight() const { return -1; }
};