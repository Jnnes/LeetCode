#pragma once
#include "../Common.h"


// 下面部分拷贝到答题区域

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.size() == 0)
            return 0;

        vector<long> dp(triangle[triangle.size() - 1].size(), INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < triangle.size(); i++) {
            for (int j = triangle[i].size() - 1; j >= 0; j--) {
                if (j > 0)
                    dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
                else
                    dp[j] = dp[j] + triangle[i][j];
            }
        }

        int ret = INT_MAX;
        for (int a : dp) {
            ret = min(ret, a);
        }
        return ret;
    }
};

// 上面部分拷贝到答题区域


// 测试框架必备
vector<vector<int>> generateTestData() {
    vector<vector<int>> ret = { {2},{3,4}, {6,5,7},{4,1,8,3} };
    return ret;
}

void run(Solution so) {
    auto testData = generateTestData();
    auto ret = so.minimumTotal(testData);
    ret = ret;
}