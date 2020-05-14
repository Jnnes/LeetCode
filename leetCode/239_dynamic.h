#pragma once
#include "Common.h"



class Solution {
public:
    // ��̬�滮�ⷨ
    /*
    1. ��Ϊ���㷨�ĺ���˼���ǣ������ڷָ�����������֣��������������ֵ�����Ϊ���ڳ���k
    2. ����kΪ������������ң������������������洢������leftʱ�����Ա�֤left[i]�Ƿָ�ڵļ��m����i�����ֵ
    3. ͬ����������ʱ��right[j]�Ƿָ�ڵļ��m����j�����ֵ
    4. ���Ҵ��� j -- i = j -- m  +  m -- i
    5. Ҳ�����ڵ����ֵΪmax(lefe[i], right[j])
    */
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
        if (k < 0 or k > nums.size())
            return ret;

        vector<int> left(nums.size());
        vector<int> right(nums.size());

        int maxi = INT_MIN;
        // �������ұ�����
        for (int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
            left[i] = maxi;

            if (i % k == k - 1) {
                maxi = INT_MIN;
            }
        }

        // �����������
        maxi = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; i--) {
            maxi = max(maxi, nums[i]);
            right[i] = maxi;

            if (i % k == 0)
                maxi = INT_MIN;
        }

        for (int i = k - 1; i < nums.size(); i++) {
            ret.push_back(max(left[i], right[i - k + 1]));
        }

        return ret;
    }
};


// ���Կ�ܱر�
vector<int> generateTestData() {
    auto ret = vector<int>{ 1,-1 };
    return ret;
}

void run(Solution so) {
    auto testData = generateTestData();

    // do algrithme
    auto ret = so.maxSlidingWindow(testData, 1);
    print(ret);
}