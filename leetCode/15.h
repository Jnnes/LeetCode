#pragma once
#include "Common.h"


// 下面部分拷贝到答题区域

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> vecvec;
        if (nums.size() < 3 || nums[0] > 0 || nums[nums.size() - 1] < 0)
            return vecvec;
        vecvec.push_back({ -1,-1,-1});
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0)
                continue;

            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                if (nums[i] + nums[left] + nums[right] == 0) {
                    if (vecvec[vecvec.size() - 1][0] != nums[i] || vecvec[vecvec.size() - 1][1] != nums[left] || vecvec[vecvec.size() - 1][2] != nums[right])
                        vecvec.push_back({nums[i],  nums[left], nums[right]});                    
                    
                    left++;
                }
                else if (nums[i] + nums[left] + nums[right] < 0) {
                    left++;
                }
                else
                    right--;
            }

            while (i < nums.size() - 1 && nums[i + 1] == nums[i])
                i++;
        }  

        for (int i = 0; i < vecvec.size() - 1; i++) {
                vecvec[i] = vecvec[i + 1];
        }
        
        vecvec.pop_back();

        return vecvec;
    }
};

// 上面部分拷贝到答题区域


// 测试框架必备
vector<int> generateTestData() {
    vector<int> ret = {-1,0,1,2,-1,-4};
    return ret;
}

void run(Solution so) {
    auto testData = generateTestData();
    auto ret = so.threeSum(testData);
    ret = ret;
}