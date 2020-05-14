#pragma once
#include "../Common.h"

// 下面部分拷贝到答题区域

class Solution {
public:
    /*
        其实是  斐波那切数列
    */
    int climbStairs(int n) {
        int one = 0;
        int two = 1;
        int ret = 1;

        for (int i = 0; i < n; i++) {
            ret = one + two;
            one = two;
            two = ret;
        }

        return ret;
    }
};

// 上面部分拷贝到答题区域


// 测试框架必备
int generateTestData() {
    
    return 0;
}

void run(Solution so) {
    auto testData = generateTestData();
    auto ret = so.climbStairs(testData);
    print(ret);
}