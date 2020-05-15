#pragma once
#include "../Common.h"

// 下面部分拷贝到答题区域
class Solution {
public:
    /*
        
    */
    int mySqrt(int x) {
        if (x <= 1)
            return x;
        if (x <= 4)
            return x / 2;
        
        long left = 0;
        long right = x;
        long ret = 0;
        while (left < right - 1) {
            ret = (left + right) / 2;
            if (ret * ret > x) {
                right = ret;
            }
            else if (ret * ret < x)
            {
                left = ret;
            }
            else
                return ret;
        }

        return left;
    }
};

// 上面部分拷贝到答题区域


// 测试框架必备
int generateTestData() {

    return 8;
}

void run(Solution so) {
    auto testData = generateTestData();
    auto ret = so.mySqrt(testData);
    print(ret);
}