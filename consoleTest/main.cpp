
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <stack>
#include <queue>
#include <sstream>
#include <string>
#include<unordered_set>
#include<math.h>
#include"Common.h"

class Solution {
public:
    int findShortestSubArray(vector<int> nums) {
        map<int, pair<int, pair<int, int>>> mn;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (mn.find(num) != mn.end()) {
                mn[num].first++;
                //mn[num].second.second = i;
                auto t = mn[num].second;
                t.second = i;

                auto p = t;
            }
            else {
                mn[num] = make_pair(1, make_pair(i, i));
            }
        }

        int mf = 0;
        int ml = 0;
        for (auto iter = mn.begin(); iter != mn.end(); iter++) {
            int f = iter->second.first;
            int l = iter->second.second.second - iter->second.second.first + 1;
            if (f > mf) {
                ml = l;
                mf = f;
            }
            else if (f == mf) {
                ml = min(ml, l);
            }
        }

        return ml;
    }

    
};

// 通过引用不同文件实现切换不同算法解决方案
#include "algorithm/maxBalloon.h"

int main() {    
    MaxBalloon so;
    so.execute();
    system("pause");
    return 0;
}