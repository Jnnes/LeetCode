#pragma once
#include "Common.h"



class Solution {
public:
    
    bool isValid(string s) {
        unordered_map<char, char> hm;
        hm[')'] = '(';
        hm['}'] = '{';
        hm[']'] = '[';

        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char tc = s[i];

            if (tc == '(' || tc == '[' || tc == '{')
                st.push(tc);
            else if (tc == ')' || tc == '}' || tc == ']') {
                if (not st.empty() and st.top() == hm[tc])
                    st.pop();
                else
                    return false;
            }
        }

        if (st.empty())
            return true;
        else
            return false;
    }
};


// ²âÊÔ¿ò¼Ü±Ø±¸
string generateTestData() {

    return ")";
}

void run(Solution so) {
    auto testData = generateTestData();

    // do algrithme
    auto ret = so.isValid(testData);
    ret = ret;
}