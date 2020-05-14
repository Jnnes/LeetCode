#pragma once
#include "Common.h"



class Solution {
public:
    // 动态规划解法
    /*
    1. 因为该算法的核心思想是：将窗口分割成左右两部分，所以左右两部分的数量为窗口长度k
    2. 当以k为间隔，从左向右，计算数组的最大数并存储在数据left时，可以保证left[i]是分割窗口的间隔m，到i的最大值
    3. 同理，从右向左时，right[j]是分割窗口的间隔m，到j的最大值
    4. 并且窗口 j -- i = j -- m  +  m -- i
    5. 也即窗口的最大值为max(lefe[i], right[j])
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (k < 0 or k > nums.size())
            return ret;

        vector<int> left(nums.size());
        vector<int> right(nums.size());

        int maxi = INT_MIN;
        // 从左往右遍历，
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
            left[i] = maxi;

            if (i % k == k - 1) {
                maxi = INT_MIN;
            }
        }

        // 从右往左遍历
        maxi = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            maxi = max(maxi, nums[i]);
            right[i] = maxi;

            if (i % k == 0)
                maxi = INT_MIN;
        }

        for (int i = k - 1; i < nums.size(); i++) {
            ret.push_back(max(left[i], right[i - k + 1]));
        }

        return ret;
    }
};


// 测试框架必备
vector<int> generateTestData() {
    auto ret = vector<int>{ 1,-1 };
    return ret;
}

void run(Solution so) {
    auto testData = generateTestData();

    // do algrithme
    auto ret = so.maxSlidingWindow(testData, 1);
    print(ret);
}