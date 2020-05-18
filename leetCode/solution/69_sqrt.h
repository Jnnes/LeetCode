#pragma once
#include "../Common.h"

// ���沿�ֿ�������������
class Solution {
public:
    /*
        ���ַ�
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

    /*
        ţ�ٵ���������Ϊ���ܴӴ�С�������򽥽���������Ҫ�����������ж�
    */
    int mySqrtNewton(int a) {
        if (a <= 1)
            return a;
        else if (a <= 4)
            return a / 2;

        long ret = a;

        while (true) {
            ret = ret - (ret * ret - a) / ret / 2;

            if (ret * ret <= a && (ret + 1) * (ret + 1) > a)
                return ret;

            if (ret * ret > a && (ret - 1) * (ret - 1) <= a)
                return ret - 1;
        }
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