#pragma once
#include "../Common.h"

// ���沿�ֿ�������������
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

// ���沿�ֿ�������������


// ���Կ�ܱر�
int generateTestData() {

    return 8;
}

void run(Solution so) {
    auto testData = generateTestData();
    auto ret = so.mySqrt(testData);
    print(ret);
}