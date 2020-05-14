#pragma once
#include "Common.h"



class Solution {
public:
    // ˫�˶��нⷨ
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (nums.size() < k)
            return ret;

        deque<int> que;
        for (int i = 0; i < nums.size(); i++) {
            while (que.size() != 0 && i - que.front() >= k )
                que.pop_front();

            while (que.size() != 0 && nums[que.back()] < nums[i]) {
                que.pop_back();                
            }

            que.push_back(i);

            if (i >= k - 1)
                ret.push_back(nums[que.front()]);
        }

        return ret;
    }
};


// ���Կ�ܱر�
vector<int> generateTestData() {
    auto ret = vector<int>{ 1, -1 };
    return ret;
}

void run(Solution so) {
    auto testData = generateTestData();

    // do algrithme
    auto ret = so.maxSlidingWindow(testData, 1);
    print(ret);
}