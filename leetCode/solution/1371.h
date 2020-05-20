#pragma once
#pragma once
#include "../Common.h"


// 下面部分拷贝到答题区域

class Solution {
public:
    /*
        1371. 每个元音包含偶数次的最长字符串，包含偶数元音字符的最长子串，
        因为每个字符只存在偶数次和奇数次两个状态，并且，奇数- 奇数 = 偶数，偶数 - 偶数 = 偶数。
        那么就可以知道，只要记录了第一个状态的位置，以后每次到相同状态，
        那个该位置到该状态第1次出现的位置（不包含首次出现改状态的位置）所有的元音字符肯定是偶数次。

        至于状态的表示，我们可以使用二进制，每一位表示一个元音字符，使用异或来翻转位，达到奇数与偶数之间的切换

        需要让人费解的是 pos[0] = 0;，以及 pos[status] = i + 1;
    */
    int findTheLongestSubstring(string s) {
        int status = 0, ans = 0;
        vector<int> pos(32, -1);
        pos[0] = 0;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'a')
                status ^= 1 << 0;
            else if (c == 'e')
                status ^= 1 << 1;
            else if (c == 'i')
                status ^= 1 << 2;
            else if (c == 'o')
                status ^= 1 << 3;
            else if (c == 'u')
                status ^= 1 << 4;

            if (pos[status] != -1)
                ans = max(ans, i + 1 - pos[status]);
            else
                pos[status] = i + 1;
            /*
               上面记录的位置需要+1，并且需要设置pos[0] = 0，
               pos[0] = 0是因为当开始如果第一个字母不为元音，那么status = 0，并且这个非元音是可以加到结果偶数子串的，
               如果按照原来算法的目的，后面状态的位置减去第一次出现状态的位置，那么长度是不包括第一次出现的那个字符的，
               所以，如果首先出现非元音，为了使第一个也被计数，则需要让status = 0时从第一个之前开始，也即pos[0] = 0;
               不能等于-1是因为 -1已经被当做判断是否已经记录过状态。基于此，因为0位置标示第一个字符之前，
               所以第1个字符也即索引0位置其实是位置1，所以后面记录位置时需要往后偏移1.

               或者是使用 -2来表示未记录状态，-1表示第一个字符前的位置，则后面记录位置就不需要偏移了。 findTheLongestSubstring2
            */
        }

        return ans;
    }

    int findTheLongestSubstring2(string s) {
        int status = 0, ans = 0;
        vector<int> pos(32, -2);
        pos[0] = -1;
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == 'a')
                status ^= 1 << 0;
            else if (c == 'e')
                status ^= 1 << 1;
            else if (c == 'i')
                status ^= 1 << 2;
            else if (c == 'o')
                status ^= 1 << 3;
            else if (c == 'u')
                status ^= 1 << 4;

            if (pos[status] != -2)
                ans = max(ans, i - pos[status]);
            else
                pos[status] = i;
            /*               
               或者是使用 -2来表示未记录状态，-1表示第一个字符前的位置，则后面记录位置就不需要偏移了。
            */
        }

        return ans;
    }
};

// 上面部分拷贝到答题区域


// 测试框架必备
string generateTestData() {
    return "leetcodeisgreat";
}

void run(Solution so) {
    auto testData = generateTestData();
    auto ret = so.findTheLongestSubstring(testData);
    ret = ret;
}