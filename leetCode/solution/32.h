#pragma once
#include "../Common.h"

class Solution {
public:
    /*
        用两个栈分别存当前待出栈字符，和已经合并的数量
    */
    int longestValidParentheses(string s) {
        stack<char> st;
        stack<int> sti;
        for (char c : s) {
            if (c == ')') {
                if (!st.empty() && st.top() == '(') {

                    int count = 2;
                    while (not st.empty() and sti.top() != 0) {
                        count += sti.top();
                        sti.pop();
                    }

                    sti.pop();
                    sti.push(count);
                    st.pop();
                }
                else {
                    st.push(')');
                    sti.push(-1);
                }
            }
            else if (c == '(') { 
                st.push('(');
                sti.push(0);
            }            
        }

        int ret = 0;
        int count = 0;
        while (not sti.empty()) {
            int value = sti.top();
            if (value > 0) {
                count += value;
            }
            else
                count = 0;

            sti.pop();
            ret = max(ret, count);
        }

        return ret;
    }
};


// 测试框架必备
string generateTestData() {

    return "()())(()";
}

void run(Solution so) {
    auto testData = generateTestData();

    // do algrithme
    auto ret = so.longestValidParentheses(testData);
    ret = ret;
}