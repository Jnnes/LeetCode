#pragma once
#include "../Common.h"

// 下面部分拷贝到答题区域

class Solution {
public:
    /*
        
    */
    void reverseString(vector<char>& s) {
        int size = s.size();
        for (int i = 0; i < s.size() / 2; i++) {
            char t = s[i];
            s[i] = s[size - i - 1];
            s[size - i - 1] = t;
        }
    }
};

// 上面部分拷贝到答题区域


// 测试框架必备
vector<char> generateTestData() {

    return vector<char>{};
}

void run(Solution so) {
    auto testData = generateTestData();
    so.reverseString(testData);
    //print(ret);
}