#pragma once
#include "../Common.h"

class ShortestSubArray : public BaseSolution
{
public:
    ShortestSubArray();
    ~ShortestSubArray();
    void init();
    void run();
    void result();
private:
    vector<int> numVec;
    int res;
};

ShortestSubArray::ShortestSubArray()
{
}

ShortestSubArray::~ShortestSubArray()
{
}

void ShortestSubArray::init() {
    numVec = vector<int>{1,2,3,4,5,6,7,8,9,0};
    print(numVec);
}

int findShortestSubArray(vector<int> nums);
void ShortestSubArray::run() {
    res = findShortestSubArray(numVec);
}

void ShortestSubArray::result() {
    std::cout << "result = " << res << std::endl;
}

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