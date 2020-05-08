#pragma once
#include "Common.h"

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curNum = nums[0];
        int count = 1;


        /*
            �����֮ǰ����Ϊ����������ͬ����ô����Ϊ������Ŀ����һ����
            �����ͬ����ô�͸�������Ŀ��һ��
            ��Ϊ�������ִ�������n / 2����ô������Ŀ���ղ��ᱻ����0
            ��������˷���������ô�÷������϶��ᱻ����0�������Ǳ����������Ǳ�����������
            ֻ�м������������Ų��ᱻ����0�����Ľ���϶�������
        */
        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                curNum = nums[i];
                count = 1;
            }
            else {
                if (curNum == nums[i])
                    count++;
                else
                    count--;
            }
        }

        return curNum;
    }
};

// ���Կ�ܱر�
vector<int> generateTestData() {
    vector<int> ret = { 2,2,1,1,1,2,2};
    return ret;
}

void run(Solution so) {
    auto testData = generateTestData();

    // do algrithme
    auto ret = so.majorityElement(testData);
    ret = ret;
}