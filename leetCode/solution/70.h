#pragma once
#include "../Common.h"

// ���沿�ֿ�������������

class Solution {
public:
    /*
        ��ʵ��  쳲���������
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

// ���沿�ֿ�������������


// ���Կ�ܱر�
int generateTestData() {
    
    return 0;
}

void run(Solution so) {
    auto testData = generateTestData();
    auto ret = so.climbStairs(testData);
    print(ret);
}