#pragma once
#include "Common.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curNum = nums[0];
        int count = 1;


        /*
            如果和之前假设为众数的数相同，那么就认为众数数目增加一个，
            如果不同，那么就给众数数目减一。
            因为众数出现次数大于n / 2，那么众数数目最终不会被减至0
            如果假设了非众数，那么该非众数肯定会被减至0，不管是被众数或者是被其他非众数
            只有假设了众数，才不会被减至0，最后的结果肯定是众数
        */
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                curNum = nums[i];
                count = 1;
            }
            else {
                if (curNum == nums[i])
                    count++;
                else
                    count--;
            }
        }

        return curNum;
    }
};

// 测试框架必备
vector<int> generateTestData() {
    vector<int> ret = { 2,2,1,1,1,2,2};
    return ret;
}

void run(Solution so) {
    auto testData = generateTestData();

    // do algrithme
    auto ret = so.majorityElement(testData);
    ret = ret;
}