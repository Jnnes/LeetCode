#pragma once
#include "../Common.h"

// ���沿�ֿ�������������

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

// ���沿�ֿ�������������


// ���Կ�ܱر�
vector<char> generateTestData() {

    return vector<char>{};
}

void run(Solution so) {
    auto testData = generateTestData();
    so.reverseString(testData);
    //print(ret);
}