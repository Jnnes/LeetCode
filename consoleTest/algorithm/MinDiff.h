#pragma once
#include "../BaseSolution.h"
#include "../Common.h"

// 1200 最小绝对差
vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    if (arr.size() < 2)
        return vector<vector<int>>();
    sort(arr.begin(), arr.end());
    int min = INT_MAX;

    vector<int> vecDIff(arr.size(), INT_MAX);
    for (int i = 1; i < arr.size(); i++) {
        int diff = arr[i] - arr[i - 1];
        vecDIff[i] = diff;
        min = min > diff ? diff : min;
    }

    vector<vector<int>> ret;
    for (int i = 0; i < arr.size(); i++)
    {
        if (vecDIff[i] == min) {
            vector<int> tempvec{ arr[i - 1], arr[i] };
            ret.push_back(tempvec);
        }
    }
    
    return ret;
}

class MinDiff :public BaseSolution
{
public:
    void init(void);
    void run(void);
    void result(void);
};

void MinDiff::init() {
}

void MinDiff::run() {
    cout << "结果为：" <<  endl;
    vector<int> vecint{ 1 };
    auto ret = minimumAbsDifference(vecint);
    for (auto iter = ret.begin(); iter != ret.cend(); iter++) {
        // print函数没有适配二维数组
        print(*iter);
    }
}

void MinDiff::result() {
}