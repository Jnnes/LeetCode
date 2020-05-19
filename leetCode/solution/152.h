#pragma once
#include "../Common.h"


// 下面部分拷贝到答题区域

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> Fmax(nums);
        vector<int> Fmin(nums);

        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];
            Fmax[i] = max(Fmax[i - 1] * num, max(Fmin[i - 1] * num, num));
            Fmin[i] = min(Fmax[i - 1] * num, min(Fmin[i - 1] * num, num));
        }

        int ret = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            ret = max(Fmax[i], ret);
        }

        return ret;
    }
};

// 上面部分拷贝到答题区域


// 测试框架必备
vector<int> generateTestData() {
    vector<int> ret = { 2,3,-2,4 };
    return ret;
}

void run(Solution so) {
    auto testData = generateTestData();
    auto ret = so.maxProduct(testData);
    ret = ret;
}