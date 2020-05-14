#pragma once
#include "Common.h"



class Solution {
public:
    // 双端队列解法
    /*
    1. 双端队列内存储索引
    2. 往队尾压数据时往队列前寻找，保证队列是递减队列
    3. 因为存储的是索引，所以可以很方便判断队列头是否在窗口内，如果超出窗口直接删除即可
    3. 因为从队尾压数据时删除了比被压入数小的数，所以可以保证队头的数肯定是队列内最大的数
    4. 如果队列头的索引不是窗口的左边，那么只可能是窗口左边的数都比队列头的数小，导致压入当前队头的数时将窗口左边的数弹出了
    */
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


// 测试框架必备
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