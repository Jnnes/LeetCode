#pragma once
#include "Common.h"



class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string str : tokens) {
            if (str == "+") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b + a);
            }
            else if (str == "-") {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b - a);
            }
            else if (str == "*")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b * a);
            }
            else if(str == "/")
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push(b / a);
            }
            else {
                st.push(atoi(str.c_str()));
            }
        }

        return st.top();
    }
};


// ≤‚ ‘øÚº‹±ÿ±∏
vector<string> generateTestData() {
    auto ret = vector<string>{ "4", "13", "5", "/", "+"};
    return ret;
}

void run(Solution so) {
    auto testData = generateTestData();

    // do algrithme
    auto ret = so.evalRPN(testData);
    ret = ret;
}