#pragma once
#include "sort_stepper.hpp"
#include <vector>
#include <stack>
#include <tuple>

class MergeSortStepper : public SortStepper {
    struct MergeTask {
        int left, mid, right;
        int i, j, k;
        std::vector<int> leftArr, rightArr;
        bool started = false;
    };

    std::vector<MergeTask> tasks;
    size_t currentTask = 0;
    bool finished = false;

public:
    MergeSortStepper(int n) {
        // Prepare all merge tasks (bottom-up merge sort)
        for (int size = 1; size < n; size *= 2) {
            for (int left = 0; left < n; left += 2 * size) {
                int mid = std::min(left + size - 1, n - 1);
                int right = std::min(left + 2 * size - 1, n - 1);
                tasks.push_back({left, mid, right, 0, 0, left, {}, {}, false});
            }
        }
    }

    bool step(std::vector<int>& values) override {
        if (finished || currentTask >= tasks.size()) {
            finished = true;
            return false;
        }

        auto& task = tasks[currentTask];
        if (!task.started) {
            task.leftArr.assign(values.begin() + task.left, values.begin() + task.mid + 1);
            task.rightArr.assign(values.begin() + task.mid + 1, values.begin() + task.right + 1);
            task.i = 0;
            task.j = 0;
            task.k = task.left;
            task.started = true;
        }

        if (task.i < task.leftArr.size() && task.j < task.rightArr.size()) {
            if (task.leftArr[task.i] <= task.rightArr[task.j]) {
                values[task.k++] = task.leftArr[task.i++];
            } else {
                values[task.k++] = task.rightArr[task.j++];
            }
            return true;
        } else if (task.i < task.leftArr.size()) {
            values[task.k++] = task.leftArr[task.i++];
            return true;
        } else if (task.j < task.rightArr.size()) {
            values[task.k++] = task.rightArr[task.j++];
            return true;
        } else {
            // Merge finished, move to next task
            currentTask++;
            return true;
        }
    }

    int getLeft() const override {
        if (finished || currentTask >= tasks.size()) return -1;
        return tasks[currentTask].left;
    }
    int getMid() const override {
        if (finished || currentTask >= tasks.size()) return -1;
        return tasks[currentTask].mid;
    }
    int getRight() const override {
        if (finished || currentTask >= tasks.size()) return -1;
        return tasks[currentTask].right;
    }
    int getCurrentIndex() const override {
        if (finished || currentTask >= tasks.size()) return -1;
        return tasks[currentTask].k;
    }
};