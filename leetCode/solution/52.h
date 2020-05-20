#pragma once
#pragma once
#include "../Common.h"


// 下面部分拷贝到答题区域

class Solution {
public:
    /*
        52. 两个链表的第一个公共节点
        一种非常简单清楚的写法，就是先找到长度差距，然后偏移差距再同步向后查找，如果有公共节点那么肯定能够找到一样的
        
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB)
            return NULL;
        ListNode * pa = headA, *pb = headB;

        int cnta = 0;
        while (pa) {
            cnta++;
            pa = pa->next;
        }

        int cntb = 0;
        while (pb) {
            cntb++;
            pb = pb->next;
        }

        int diff = abs(cnta - cntb);
        pa = headA, pb = headB;
        if (cnta > cntb) {
            while (diff--)
                pa = pa->next;
        }
        else {
            while (diff--)
                pb = pb->next;
        }

        while (pa != pb && pa != NULL) {
            pa = pa->next;
            pb = pb->next;
        }

        return pa;
    }
};
// 上面部分拷贝到答题区域


// 测试框架必备
string generateTestData() {
    return "leetcodeisgreat";
}

void run(Solution so) {
    //auto testData = generateTestData();
    //auto ret = so.getIntersectionNode(testData);
    //ret = ret;
}