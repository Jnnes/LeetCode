#pragma once
#include "Common.h"


// 下面部分拷贝到答题区域
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool haveOne = false;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                haveOne = true;
            else if (nums[i] <= 0) {
                nums[i] = 1;
            }
        }

        if (!haveOne)
            return 1;

        for (int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            if (index < nums.size() && nums[index] > 0) {
                nums[index] = 0 - nums[index];
            }
        }
        int i = 0;
        for (; i < nums.size(); i++) {
            if (nums[i] > 0)
                return i + 1;
        }

        if (i == nums.size())
            return nums.size() + 1;
        return 1;
    }
};

// 上面部分拷贝到答题区域


// 测试框架必备
vector<int> generateTestData() {
    vector<int> ret = { 1, 1000};
    return ret;
}

void run(Solution so) {
    auto testData = generateTestData();

    // do algrithme
    auto ret = so.firstMissingPositive(testData);
    ret = ret;
}